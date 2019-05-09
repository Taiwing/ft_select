/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:02:51 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/08 21:03:23 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RING_H
# define RING_H

# include "t_ftsdata.h"

t_ftselem	*ring_new(const char *str);
t_ftselem	*ring_add(t_ftselem **alst, const char *str);
void		ring_rm_elem(t_ftselem **alst);
void		ring_del_list(t_ftselem *lst);

#endif
