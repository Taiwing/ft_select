/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:36:16 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/09 12:17:56 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include "libft.h"
#include "fts_init.h"

int		tputchar(int c)
{
	return (write(0, &c, 1));
}

void	set_custom_input_mode(void)
{
	struct termios			new_tattr;

	if (tcgetattr(0, &new_tattr) == -1)
		ft_exit("tcgettattr: failed to get terminal attributes", EXIT_FAILURE);
	new_tattr.c_lflag &= ~(ICANON | ECHO);
	new_tattr.c_cc[VMIN] = 1;
	new_tattr.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSAFLUSH, &new_tattr) == -1)
		ft_exit("tcsetattr: failed to set terminal attributes", EXIT_FAILURE);
}

void	reset_input_mode(void)
{
	static struct termios	*old_tattr = NULL;
	char					**termcaps;

	termcaps = ftsd_container(NULL)->ftsp.termcaps;
	if (!old_tattr)
	{
		old_tattr = (struct termios *)ft_secmalloc(sizeof(struct termios));
		if (tcgetattr(0, old_tattr) == -1)
			ft_exit("tcgettatr: failed to get terminal attributes",
				EXIT_FAILURE);
		set_custom_input_mode();
		tputs(termcaps[TC_TI], 1, tputchar);
		tputs(termcaps[TC_VI], 1, tputchar);
	}
	else
	{
		tcsetattr(0, TCSANOW, old_tattr);
		ft_memdel((void **)&old_tattr);
		tputs(termcaps[TC_TE], 1, tputchar);
		tputs(termcaps[TC_VE], 1, tputchar);
	}
}
