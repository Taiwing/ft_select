/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_charfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 11:15:01 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/11 13:04:56 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "charfunc.h"

char	* const g_multibyte_chars[6] = {
	"\033[A",
	"\033[B",
	"\033[C",
	"\033[D",
	"\033[3~",
	NULL
};

int		(* const g_charfunc[256])(t_ftsdata *ftsd, char input[8]) = {
	[0] = discard_input,
	['\n'] = return_selection,
	['\033'] = quit,
	[' '] = select_element,
	[UP_ARROW] = move_up,
	[DOWN_ARROW] = move_down,
	[LEFT_ARROW] = move_left,
	[RIGHT_ARROW] = move_right,
	[DELETE_KEY] = delete_element,
	['!' ... '~'] = completion,
	['\177'] = delete_element,
};
