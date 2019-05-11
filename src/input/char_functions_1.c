/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 11:28:32 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/11 13:05:12 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charfunc.h"
#include "ring.h"
#include "fts_print.h"

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
		lst = lst->next;
	}
	if (lst && !lst->selected)
	{
		--ftsd->list_size;
		ring_rm_elem(&lst);
	}
	return (STOP_INPUT);
}

int	quit(t_ftsdata *ftsd, char input[8])
{
	(void)input;
	ftsd->list_size = 0;
	ring_del_list(ftsd->lst);
	return (STOP_INPUT);
}

int	select_element(t_ftsdata *ftsd, char input[8])
{
	(void)input;
	ftsd->lst->selected = !ftsd->lst->selected;
	fts_print(ftsd);
	return (CONTINUE_INPUT);
}

int	move_up(t_ftsdata *ftsd, char input[8])
{
	(void)input;
	if (ftsd->list_size > 1)
	{
		ftsd->lst = ftsd->lst->prev;
		if (--ftsd->ftsp.cursor[Y] < 0)
		{
			if (--ftsd->ftsp.cursor[X] < 0
				&& ftsd->ftsp.printable != ftsd->list_size)
			{
				if (ftsd->ftsp.printable < ftsd->list_size)
					ftsd->ftsp.cursor[X] = 0;
				else
					ftsd->ftsp.cursor[Y] = ftsd->list_size % ftsd->ftsp.grid_h;
			}
		}
		fts_print(ftsd);
	}	
	return (CONTINUE_INPUT);
}
