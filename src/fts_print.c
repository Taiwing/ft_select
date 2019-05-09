/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 22:00:55 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/09 13:43:27 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_ftsdata.h"

static int	reset_screen(t_ftsdata *ftsd, t_ftsprint *ftsp)
{
	(void)ftsd;
	(void)ftsp;
	return (0);
}

int		fts_print(t_ftsdata *ftsd)
{
	t_ftsprint	*ftsp;

	ftsp = &ftsd->ftsp;
	if (ftsp->scroll != ftsd->term_h || ftsp->printable < ftsd->list_size)
	{
		if (ftsp->cursor[X] < 0 || ftsp->cursor[X] >= ftsp->grid_w)
			ftsp->cursor[X] = ftsp->cursor[X] < 0 ? 0 : ftsp->grid_w - 1;
		else if (ftsp->cursor[Y] < 0 || ftsp->cursor[Y] >= ftsp->grid_h)
			ftsp->cursor[Y] = ftsp->cursor[Y] < 0 ? ftsp->grid_h - 1 : 0;
		reset_screen(ftsd, ftsp);
	}
	else
	{
		//print from
		//print lst
	}
	ftsp->from = ftsd->lst;
	return (0);
}
