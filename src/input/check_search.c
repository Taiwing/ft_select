/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:24:06 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/24 16:47:38 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_ftsdata.h"
#include "libft.h"

int	check_search(t_ftsdata *ftsd)
{
	t_ftselem	*lst;

	if (!(lst = ftsd->lst))
		return (0);
	while (lst && ft_strncmp(lst->str, ftsd->search, ftsd->s_cursor))
	{
		if ((lst = lst->next) == ftsd->lst)
			return (0);
	}
	ftsd->ftsp.from = NULL;
	ftsd->ftsp.scroll = 0;
	ftsd->lst = lst;
	return (1);
}
