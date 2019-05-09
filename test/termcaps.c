#include <termcap.h>
#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <ctype.h>

#define TERMC	5
#define WIDTH	0
#define HEIGHT	1
#define X		0
#define Y		1

enum	e_terms {TC_CM = 0, TC_TI, TC_TE, TC_VI, TC_VE};

void	exit_err(const char *err)
{
	dprintf(2, "%s\n", err);
	exit(EXIT_FAILURE);
}

void	init_termcaps(char *termcaps[TERMC])
{
	char	*term_name;
	int		ent;

	if (!isatty(0))
		exit_err("isatty: is no tty brother");
	if (!(term_name = getenv("TERM")))
		exit_err("getenv: could not get terminal name");
	if (!(ent = tgetent(NULL, term_name)))
		exit_err("tgetent: terminal not found");
	else if (ent < 0)
		exit_err("tgetent: terminfo database not found");
	if (!(termcaps[TC_CM] = tgetstr("cm", NULL)))
		exit_err("tgetstr: 'cm' termcap not found");
	if (!(termcaps[TC_TI] = tgetstr("ti", NULL)))
		exit_err("tgetstr: 'ti' termcap not found");
	if (!(termcaps[TC_TE] = tgetstr("te", NULL)))
		exit_err("tgetstr: 'te' termcap not found");
	if (!(termcaps[TC_VI] = tgetstr("vi", NULL)))
		exit_err("tgetstr: 'vi' termcap not found");
	if (!(termcaps[TC_VE] = tgetstr("ve", NULL)))
		exit_err("tgetstr: 've' termcap not found");
}

void	get_term_size(int term_size[2])
{
	struct winsize	w;

	if (ioctl(0, TIOCGWINSZ, &w) < 0)	
		exit_err("ioctl: could not get terminal size");
	term_size[WIDTH] = w.ws_col;
	term_size[HEIGHT] = w.ws_row;
}

void	set_custom_input_mode(void)
{
	struct termios			new_tattr;

	if (tcgetattr(0, &new_tattr) == -1)
		exit_err("tcgettattr: failed to get terminal attributes");
	new_tattr.c_lflag &= ~(ICANON | ECHO);
	new_tattr.c_cc[VMIN] = 1;
	new_tattr.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSAFLUSH, &new_tattr) == -1)
		exit_err("tcsetattr: failed to set terminal attributes");
}

void	reset_input_mode(char *termcaps[TERMC])
{
	static struct termios	*old_tattr = NULL;

	if (!old_tattr)
	{
		old_tattr = (struct termios *)malloc(sizeof(struct termios));
		if (tcgetattr(0, old_tattr) == -1)
			exit_err("tcgettatr: failed to get terminal attributes");
		set_custom_input_mode();
		tputs(termcaps[TC_TI], 1, putchar);
		fflush(stdout);
	}
	else
	{
		tcsetattr(0, TCSANOW, old_tattr);
		free(old_tattr);
		tputs(termcaps[TC_TE], 1, putchar);
		fflush(stdout);
	}
}

void	print_lol_screen(char *termcaps[TERMC], int term_size[2])
{
	int		i;

	tputs(termcaps[TC_VI], 1, putchar);
	i = -1;
	while (++i < term_size[HEIGHT])
	{
		tputs(tgoto(termcaps[TC_CM], i, i), 1, putchar);
		printf("lol (line = %d, col = %d)", i, i);
	}
	fflush(stdout);
	sleep(3);
	tputs(termcaps[TC_VE], 1, putchar);
}

int		main(int argc, char **argv)
{
	char	*termcaps[TERMC];
	int		term_size[2];

	(void)argc;
	(void)argv;
	init_termcaps(termcaps);
	reset_input_mode(termcaps);
	get_term_size(term_size);
	print_lol_screen(termcaps, term_size);
	reset_input_mode(termcaps);
	return (0);
}
