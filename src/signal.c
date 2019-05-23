/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:03:01 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/23 10:34:37 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "libft.h"
#include "terminal_mode.h"
#include "fts_init.h"
#include "fts_print.h"

static void	refresh_screen(t_ftsdata *ftsd)
{
	get_term_size(ftsd);
	ftsd->ftsp.scroll = 0;
	fts_print(ftsd);
}

void		signal_hand(int sig)
{
	int			proc;
	t_ftsdata	*ftsd;

	if (sig == SIGINT)
		ft_exit(NULL, EXIT_FAILURE);
	else if (sig == SIGTSTP)
	{
		ft_atexit(NULL);
		signal(SIGTSTP, SIG_DFL);
		ioctl(2, TIOCSTI, "\x1A");
	}
	else if (sig == SIGCONT)
	{
		signal(SIGTSTP, signal_hand);
		ft_atexit(reset_input_mode);
		reset_input_mode();
		ftsd = ftsd_container(NULL);
		if (ftsd->term_proc != (proc = ttyslot()))
		{
			ftsd->term_proc = proc;
			init_termcaps(ftsd);
		}
		refresh_screen(ftsd);
	}
	else if (sig == SIGWINCH)
		refresh_screen(ftsd_container(NULL));
}
