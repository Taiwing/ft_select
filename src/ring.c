/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:02:29 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/09 12:11:12 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_ftsdata.h"
#include "libft.h"

t_ftselem	*ring_new(const char *str)
{
	t_ftselem	*new;

	if ((new = (t_ftselem *)ft_secmalloc(sizeof(t_ftselem))))
	{
		new->selected = 0;
		new->str = str;
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}

t_ftselem	*ring_add(t_ftselem **alst, const char *str)
{
	t_ftselem	*new;

	if (!alst || !(new = ring_new(str)))
		return (NULL);
	if (*alst)
	{
		new->next = (*alst)->next;
		if (new->next)
			new->next->prev = new;
		new->prev = (*alst);
		(*alst)->next = new;
	}
	*alst = new;
	return (new);
}

void		ring_rm_elem(t_ftselem **alst)
{
	t_ftselem	*prev;
	t_ftselem	*next;

	if (!alst || !*alst)
		return ;
	prev = (*alst)->prev;
	next = (*alst)->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	free(ft_heap_collector(*alst, FT_COLLEC_GET));
	if (prev != next)
		*alst = prev ? prev : next;
	else
		*alst = prev == *alst ? NULL : prev;
}

void		ring_del_list(t_ftselem *lst)
{
	if (!lst)
		return ;
	if (lst->prev)
		lst->prev->next = NULL;
	if (lst->next)
		lst->next->prev = NULL;
	ring_del_list(lst->next);
	free(ft_heap_collector(lst, FT_COLLEC_GET));
}
