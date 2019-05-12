/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 11:29:52 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/11 18:28:19 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "charfunc.h"
#include "ring.h"
#include "fts_print.h"
#include "cursor.h"

int	move_down(t_ftsdata *ftsd, char input[8])
{
	(void)input;
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
	if (ftsd->list_size > 1)
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
	if (ftsd->list_size > 1)
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
	ring_rm_elem(&ftsd->lst);
	--ftsd->list_size;
	ftsd->ftsp.from = NULL;
	ftsd->ftsp.scroll = 0;
	/*TODO: reset elem_size if needed*/
	fts_print(ftsd);
	return (CONTINUE_INPUT);
}

//TODO
int	completion(t_ftsdata *ftsd, char input[8])
{
	(void)ftsd;
	(void)input;
	return (CONTINUE_INPUT);
}
