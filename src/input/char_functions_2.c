/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 11:29:52 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/24 17:16:35 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "charfunc.h"
#include "ring.h"
#include "fts_print.h"
#include "cursor.h"
#include "print_interface.h"
#include "check_search.h"

int	move_down(t_ftsdata *ftsd, char input[8])
{
	(void)input;
	if (ftsd->search)
	{
		ft_strdel(&ftsd->search);
		print_interface(ftsd, &ftsd->ftsp);
	}
	if (ftsd->list_size > 1)
	{
		ftsd->lst = ftsd->lst->next;
		move_cursor_down(&ftsd->ftsp, ftsd->list_size, 1);
		fts_print(ftsd);
	}	
	return (CONTINUE_INPUT);
}

int	move_right(t_ftsdata *ftsd, char input[8])
{
	int	i;

	(void)input;
	if (ftsd->search)
	{
		ft_strdel(&ftsd->search);
		print_interface(ftsd, &ftsd->ftsp);
	}
	if (ftsd->list_size > 1
		&& (ftsd->ftsp.grid_w > 1 || ftsd->ftsp.grid_h == 1))
	{
		i = ftsd->ftsp.grid_h + 1;
		while (--i)
			ftsd->lst = ftsd->lst->next;
		move_cursor_down(&ftsd->ftsp, ftsd->list_size, ftsd->ftsp.grid_h);
		fts_print(ftsd);
	}
	return (CONTINUE_INPUT);
}

int	move_left(t_ftsdata *ftsd, char input[8])
{
	int	i;

	(void)input;
	if (ftsd->search)
	{
		ft_strdel(&ftsd->search);
		print_interface(ftsd, &ftsd->ftsp);
	}
	if (ftsd->list_size > 1
		&& (ftsd->ftsp.grid_w > 1 || ftsd->ftsp.grid_h == 1))
	{
		i = ftsd->ftsp.grid_h + 1;
		while (--i)
			ftsd->lst = ftsd->lst->prev;
		move_cursor_up(&ftsd->ftsp, ftsd->list_size, ftsd->ftsp.grid_h);
		fts_print(ftsd);
	}
	return (CONTINUE_INPUT);
}

int	delete_element(t_ftsdata *ftsd, char input[8])
{
	(void)input;
	if (ftsd->search)
		ft_strdel(&ftsd->search);
	ring_rm_elem(&ftsd->lst);
	--ftsd->list_size;
	ftsd->ftsp.from = NULL;
	ftsd->ftsp.scroll = 0;
	/*TODO: reset elem_size if needed*/
	fts_print(ftsd);
	return (CONTINUE_INPUT);
}

int	search_element(t_ftsdata *ftsd, char input[8])
{
	if ((!ftsd->s_valid && ftsd->search)
		|| ftsd->s_cursor >= ftsd->ftsp.elem_size)
		ft_strdel(&ftsd->search);
	if (!ftsd->search)
	{
		ftsd->search = ft_strnew(ftsd->ftsp.elem_size);
		ftsd->s_cursor = 0;
	}
	ftsd->search[ftsd->s_cursor++] = input[0];
	if ((ftsd->s_valid = check_search(ftsd)))
		fts_print(ftsd);
	else
		print_interface(ftsd, &ftsd->ftsp);
	return (CONTINUE_INPUT);
}
