/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:24:06 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/04 09:36:33 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"
#include "libft.h"

static void	move_to_result(t_ftsdata *ftsd, t_ftsprint *ftsp,
							t_ftselem *lst, int move)
{
	int	cur;

	cur = (ftsp->cursor[X] * ftsp->grid_h) + ftsp->cursor[Y] + 1;
	ftsp->from = ftsd->lst;
	ftsp->from_pos[X] = ftsp->cursor[X];
	ftsp->from_pos[Y] = ftsp->cursor[Y];
	ftsd->lst = lst;
	if (cur + move <= ftsp->printable)
		move_cursor_down(ftsp, ftsd->list_size, move);
	else if (ftsd->list_size - move < cur)
		move_cursor_up(ftsp, ftsd->list_size, ftsd->list_size - move);
	else
	{
		ftsp->cursor[X] = 0;
		ftsp->cursor[Y] = 0;
	}
	ftsp->scroll = 0;
}

int			check_search(t_ftsdata *ftsd)
{
	int			match;
	int			move;
	t_ftselem	*lst;

	if (!(lst = ftsd->lst))
		return (0);
	match = 0;
	move = 0;
	while (!match && (lst = lst->next) != ftsd->lst)
	{
		match = !ft_strncmp(lst->str, ftsd->search, ftsd->s_cursor);
		++move;
	}
	if (!match)
		return (0);
	move_to_result(ftsd, &ftsd->ftsp, lst, move);
	return (1);
}
