/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 17:28:20 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/11 17:31:35 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H

# include "t_ftsdata.h"

void	move_cursor_down(t_ftsprint *ftsp, int list_size, int move);
void	move_cursor_up(t_ftsprint *ftsp, int list_size, int move);

#endif
