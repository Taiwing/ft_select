/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:24:06 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/04 08:34:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_ftsdata.h"
#include "libft.h"

int	check_search(t_ftsdata *ftsd)
{
	int			match;
	t_ftselem	*lst;

	if (!(lst = ftsd->lst))
		return (0);
	match = 0;
	while (!match && (lst = lst->next) != ftsd->lst)
		match = !ft_strncmp(lst->str, ftsd->search, ftsd->s_cursor);
	if (!match)
		return (0);
	ftsd->ftsp.from = NULL;
	ftsd->ftsp.scroll = 0;
	ftsd->lst = lst;
	return (1);
}
