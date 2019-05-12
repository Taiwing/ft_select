/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:14:49 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/12 17:59:38 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <termcap.h>
#include "libft.h"
#include "t_ftsdata.h"
#include "terminal_mode.h"
#include "c_colors.h"

void		print_elem(t_ftselem *elem, int	coord[2],
					t_ftsprint *ftsp, int on_cursor)
{
	int	x;

	if (errno || !elem)
		return ;
	x = (coord[X] * (ftsp->elem_size + 1)) + ftsp->origin[X];
	tputs(tgoto(ftsp->termcaps[TC_CM], x, coord[Y]), 1, tputchar);
	//maybe clear next elem_size characters
	if (!errno)
		ft_dprintf(1, "%s%s%s%s%s" C_RESET, ftsp->colors[elem->type][FG],
			ftsp->colors[elem->type][BG], elem->selected ? C_REVERSE : "",
			on_cursor ? C_UNDERLINE : "", elem->str);
}

static int	print_back(int to_print, t_ftselem *lst,
						int coord[2], t_ftsprint *ftsp)
{
	while (to_print)
	{
		if (--coord[Y] < 0)
		{
			if (--coord[X] < 0)
				break ;
			coord[Y] += ftsp->grid_h;
		}
		print_elem(lst, coord, ftsp, 0);
		lst = lst->prev;
		--to_print;
	}
	return (to_print);
}

static int	print_front(int to_print, t_ftselem *lst,
						int coord[2], t_ftsprint *ftsp)
{
	while (to_print)
	{
		if (++coord[Y] >= ftsp->grid_h)
		{
			if (++coord[X] >= ftsp->grid_w)
				break ;
			coord[Y] = 0;
		}
		print_elem(lst, coord, ftsp, 0);
		lst = lst->next;
		--to_print;
	}
	return (to_print);
}

int			reprint_screen(t_ftsdata *ftsd, t_ftsprint *ftsp)
{
	int			to_print;
	int			coord[2];
	t_ftselem	*ptr;

	tputs(ftsp->termcaps[TC_CL], 1, tputchar);
	errno = 0;
	if ((to_print = ftsp->printable < ftsd->list_size
		? ftsp->printable : ftsd->list_size))
		print_elem(ftsd->lst, ftsp->cursor, ftsp, 1);
	if (ftsd->lst)
	{
		ptr = ftsd->lst->prev;
		coord[X] = ftsp->cursor[X];
		coord[Y] = ftsp->cursor[Y];
		to_print = print_back(to_print, ptr, coord, ftsp);
		ptr = ftsd->lst->next;
		coord[X] = ftsp->cursor[X];
		coord[Y] = ftsp->cursor[Y];
		to_print = print_front(to_print, ptr, coord, ftsp);
	}
	return (errno ? -1 : 1);
}
