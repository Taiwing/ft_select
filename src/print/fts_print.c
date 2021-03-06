/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 22:00:55 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/23 15:04:51 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "terminal_mode.h"
#include "libft.h"
#include "print_list.h"

static void	resize_grid(t_ftsdata *ftsd, t_ftsprint *ftsp)
{
	int	list_size;

	ftsp->separators = ftsd->term_w >= ftsp->elem_size + 4;
	ftsp->status_bar = ftsd->term_h > 2 && ftsd->term_w > ftsp->elem_size + 1;
	ftsp->col_w = ftsp->elem_size + (ftsp->separators ? 3 : 1);
	list_size = ftsd->list_size;
	ftsp->scroll = ftsd->term_h;
	ftsp->grid_w = 0;
	ftsp->grid_h = list_size < ftsd->term_h - ftsp->status_bar ?
		list_size : ftsd->term_h - ftsp->status_bar;
	while (ftsp->col_w <= ftsd->term_w - (ftsp->grid_w * ftsp->col_w)
			- ftsp->separators && list_size >= ftsp->grid_h)
	{
		list_size -= ftsp->grid_h;
		++ftsp->grid_w;	
	}
	ftsp->printable = ftsp->grid_w * ftsp->grid_h;
	ftsp->origin[X] = (ftsd->term_w - (ftsp->grid_w * ftsp->col_w)) / 2;
}

static int	reset_screen(t_ftsdata *ftsd, t_ftsprint *ftsp)
{
	int	reprint;

	reprint = 0;
	if (ftsp->scroll != ftsd->term_h)
	{
		resize_grid(ftsd, ftsp);
		reprint = 1;
	}
	if (ftsp->cursor[X] < 0 || ftsp->cursor[X] >= ftsp->grid_w)
	{
		ftsp->cursor[X] = ftsp->cursor[X] < 0 ? 0 : ftsp->grid_w - 1;
		reprint = 1;
	}
	if (ftsp->cursor[Y] < 0 || ftsp->cursor[Y] >= ftsp->grid_h)
	{
		ftsp->cursor[Y] = ftsp->cursor[Y] < 0 ? 0 : ftsp->grid_h - 1;
		reprint = 1;
	}
	return (reprint ? reprint_screen(ftsd, ftsp) : 0);
}

int			fts_print(t_ftsdata *ftsd)
{
	int			reset;
	t_ftsprint	*ftsp;

	ftsp = &ftsd->ftsp;
	if ((reset = reset_screen(ftsd, ftsp)) == -1)
	{
		ftsp->scroll = 0;
		return (fts_print(ftsd));
	}
	else if (!reset && ftsp->printable)
	{
		errno = 0;
		print_elem(ftsp->from, ftsp->from_pos, ftsp, 0);
		print_elem(ftsd->lst, ftsp->cursor, ftsp, 1);
		if (errno)
		{
			ftsp->scroll = 0;
			return (fts_print(ftsd));
		}
	}
	ftsp->from = ftsd->lst;
	ftsp->from_pos[X] = ftsp->cursor[X];
	ftsp->from_pos[Y] = ftsp->cursor[Y];
	return (0);
}
