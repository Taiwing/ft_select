/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charfunc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:46:27 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/11 13:04:35 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARFUNC_H
# define CHARFUNC_H

# include "t_ftsdata.h"

# define INPUT_CONTROL_CHARS	"\n\033"

# define CONTINUE_INPUT	1
# define STOP_INPUT		0

# define UP_ARROW		11
# define DOWN_ARROW		12
# define RIGHT_ARROW	13
# define LEFT_ARROW		14
# define DELETE_KEY		15

extern char	* const g_multibyte_chars[6];

extern int	(* const g_charfunc[256])(t_ftsdata *ftsd, char input[8]);

int		fts_getchar(char c[8]);

int		discard_input(t_ftsdata *ftsd, char input[8]);
int		return_selection(t_ftsdata *ftsd, char input[8]);
int		quit(t_ftsdata *ftsd, char input[8]);
int		select_element(t_ftsdata *ftsd, char input[8]);
int		move_up(t_ftsdata *ftsd, char input[8]);
int		move_down(t_ftsdata *ftsd, char input[8]);
int		move_right(t_ftsdata *ftsd, char input[8]);
int		move_left(t_ftsdata *ftsd, char input[8]);
int		delete_element(t_ftsdata *ftsd, char input[8]);
int		completion(t_ftsdata *ftsd, char input[8]);

#endif
