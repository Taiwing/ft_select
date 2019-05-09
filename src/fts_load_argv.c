/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_load_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:57:05 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/09 12:07:51 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ring.h"
#include "libft.h"

/*TODO: get types of arguments (check if they are a file) if lscolors*/ 
void	fts_load_argv(t_ftsdata *ftsd, char **argv)
{
	int			l;
	t_ftselem	*first;

	while (*++argv)
	{
		ring_add(&ftsd->lst, *argv);
		if ((l = ft_strlen(*argv)) > ftsd->elem_size)
			ftsd->elem_size = l;
		++ftsd->list_size;
	}
	first = ftsd->lst;
	while (first && first->prev)
		first = first->prev;
	if (first)
	{
		first->prev = ftsd->lst;
		ftsd->lst->next = first;
		ftsd->lst = first;
	}
}
