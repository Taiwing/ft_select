/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 11:29:52 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/11 13:17:29 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "charfunc.h"
#include "ring.h"
#include "fts_print.h"

int	move_down(t_ftsdata *ftsd, char input[8])
{
	(void)input;
	if (ftsd->list_size > 1)
	{
		ftsd->lst = ftsd->lst->next;
		++ftsd->ftsp.cursor[Y];
		if (ftsd->ftsp.printable > ftsd->list_size
			&& ftsd->ftsp.cursor[X] == ftsd->ftsp.grid_w - 1
			&& ftsd->ftsp.cursor[Y] >= ftsd->list_size % ftsd->ftsp.grid_h)
		{
			ftsd->ftsp.cursor[Y] = 0;
			ftsd->ftsp.cursor[X] = 0;
		}
		else if (ftsd->ftsp.cursor[Y] >= ftsd->ftsp.grid_h)
		{
			if (++ftsd->ftsp.cursor[X] >= ftsd->ftsp.grid_w
				&& ftsd->ftsp.printable < ftsd->list_size)
				ftsd->ftsp.cursor[X] = ftsd->ftsp.grid_w - 1;
		}
		fts_print(ftsd);
	}	
	return (CONTINUE_INPUT);
}

int	move_right(t_ftsdata *ftsd, char input[8])
{
	(void)input;
	(void)ftsd;
	return (CONTINUE_INPUT);
}

int	move_left(t_ftsdata *ftsd, char input[8])
{
	(void)input;
	(void)ftsd;
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
