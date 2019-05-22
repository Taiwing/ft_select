/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 11:28:32 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/22 14:49:30 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "charfunc.h"
#include "ring.h"
#include "fts_print.h"
#include "cursor.h"

int	discard_input(t_ftsdata *ftsd, char input[8])
{
	(void)ftsd;
	(void)input;
	return (CONTINUE_INPUT);
}

int	return_selection(t_ftsdata *ftsd, char input[8])
{
	t_ftselem	*lst;

	(void)input;
	lst = ftsd->lst ? ftsd->lst->next : ftsd->lst;
	while (lst && lst != ftsd->lst)
	{
		if (!lst->selected)
		{
			--ftsd->list_size;
			ring_rm_elem(&lst);
		}
		else
			lst = lst->next;
	}
	if (lst && !lst->selected)
	{
		--ftsd->list_size;
		ring_rm_elem(&lst);
	}
	ftsd->lst = lst;
	return (STOP_INPUT);
}

int	quit(t_ftsdata *ftsd, char input[8])
{
	(void)input;
	ftsd->list_size = 0;
	ring_del_list(ftsd->lst);
	ftsd->lst = NULL;
	return (STOP_INPUT);
}

int	select_element(t_ftsdata *ftsd, char input[8])
{
	(void)input;
	ftsd->lst->selected = !ftsd->lst->selected;
	if (ftsd->list_size > 1)
	{
		ftsd->lst = ftsd->lst->next;
		move_cursor_down(&ftsd->ftsp, ftsd->list_size, 1);
	}
	fts_print(ftsd);
	return (CONTINUE_INPUT);
}

int	move_up(t_ftsdata *ftsd, char input[8])
{
	(void)input;
	if (ftsd->list_size > 1)
	{
		ftsd->lst = ftsd->lst->prev;
		move_cursor_up(&ftsd->ftsp, ftsd->list_size, 1);
		fts_print(ftsd);
	}	
	return (CONTINUE_INPUT);
}
