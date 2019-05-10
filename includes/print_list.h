/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:31:41 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/10 16:33:31 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_LIST_H
# define PRINT_LIST_H

# include "t_ftsdata.h"

void	print_elem(t_ftselem *elem, int coord[2],
					t_ftsprint *ftsp, int on_cursor);
int		reprint_screen(t_ftsdata *ftsd, t_ftsprint *ftsp);

#endif
