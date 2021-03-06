/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 15:39:08 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/12 18:06:51 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_ftsdata.h"

void	move_cursor_down(t_ftsprint *ftsp, int list_size, int move)
{
	while (move)
	{
		if (++ftsp->cursor[Y] >= ftsp->grid_h)
		{
			ftsp->cursor[Y] = 0;
			if (++ftsp->cursor[X] >= ftsp->grid_w)
			{
				ftsp->cursor[X] = 0;
				if (ftsp->printable < list_size)
				{
					if (ftsp->grid_w > 1)
						ftsp->cursor[X] = ftsp->grid_w - 1;
					else
						ftsp->cursor[Y] = ftsp->grid_h - 1;
					ftsp->scroll = 0;
				}
			}
		}
		--move;
	}
}

void	move_cursor_up(t_ftsprint *ftsp, int list_size, int move)
{
	while (move)
	{
		if (--ftsp->cursor[Y] < 0)
		{
			ftsp->cursor[Y] = ftsp->grid_h - 1;
			if (--ftsp->cursor[X] < 0)
			{
				ftsp->cursor[X] = ftsp->grid_w - 1;
				if (ftsp->printable < list_size)
				{
					if (ftsp->grid_w > 1)
						ftsp->cursor[X] = 0;
					else
						ftsp->cursor[Y] = 0;
					ftsp->scroll = 0;
				}
			}
		}
		--move;
	}
}
