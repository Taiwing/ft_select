/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:34:27 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/22 12:14:50 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <sys/ioctl.h>
#include <signal.h>
#include "libft.h"
#include "t_ftsdata.h"
#include "terminal_mode.h"
#include "load_colors.h"
#include "signal.h"

t_ftsdata	*ftsd_container(t_ftsdata *ftsd_in)
{
	static t_ftsdata	*ftsd = NULL;

	if (ftsd_in)
		ftsd = ftsd_in;
	return (ftsd);
}

void		init_termcaps(t_ftsdata *ftsd)
{
	char	**termcaps;
	char	*term_name;

	termcaps = ftsd->ftsp.termcaps;
	if (!isatty(0))
		ft_exit("isatty: not a terminal", EXIT_FAILURE);
	if (!(term_name = getenv("TERM")))
		ft_exit("getenv: could not get terminal name", EXIT_FAILURE);
	if (tgetent(NULL, term_name) <= 0)
		ft_exit("tgetent: terminal not found", EXIT_FAILURE);
	if (!(ftsd->term_proc = ttyslot()))
		ft_exit("ttyslot: couldn't get tty process number", EXIT_FAILURE);
	if (!(termcaps[TC_CM] = tgetstr("cm", NULL)))
		ft_exit("tgetstr: 'cm' termcap not found", EXIT_FAILURE);
	if (!(termcaps[TC_TI] = tgetstr("ti", NULL)))
		ft_exit("tgetstr: 'ti' termcap not found", EXIT_FAILURE);
	if (!(termcaps[TC_TE] = tgetstr("te", NULL)))
		ft_exit("tgetstr: 'te' termcap not found", EXIT_FAILURE);
	if (!(termcaps[TC_VI] = tgetstr("vi", NULL)))
		ft_exit("tgetstr: 'vi' termcap not found", EXIT_FAILURE);
	if (!(termcaps[TC_VE] = tgetstr("ve", NULL)))
		ft_exit("tgetstr: 've' termcap not found", EXIT_FAILURE);
	if (!(termcaps[TC_CL] = tgetstr("cl", NULL)))
		ft_exit("tgetstr: 'cl' termcap not found", EXIT_FAILURE);
}

void		get_term_size(t_ftsdata *ftsd)
{
	struct winsize	w;

	if (ioctl(0, TIOCGWINSZ, &w) < 0)
		ft_exit("ioctl: couldn't get terminal size", EXIT_FAILURE);
	ftsd->term_h = w.ws_row;
	ftsd->term_w = w.ws_col;
}

static void	init_signals(void)
{
	int	i;

	i = -1;
	while (++i < 31)
		signal(i, signal_hand);
}

void		fts_init(t_ftsdata *ftsd)
{
	ft_exitmsg("ft_select");
	ftsd_container(ftsd);
	init_termcaps(ftsd);
	get_term_size(ftsd);
	reset_input_mode();
	ft_atexit(reset_input_mode);
	ftsd->ftsp.lscolors = getenv("LSCOLORS");
	load_colors(ftsd->ftsp.lscolors, ftsd->ftsp.colors);
	init_signals();
}
