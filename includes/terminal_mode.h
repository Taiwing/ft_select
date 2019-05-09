/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_mode.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:55:43 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/09 12:02:08 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_MODE_H
# define TERMINAL_MODE_H

int		tputchar(int c);
void	set_custom_input_mode(void);
void	reset_input_mode(void);

#endif
