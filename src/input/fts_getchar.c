/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_getchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 10:55:11 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/11 13:00:55 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "charfunc.h"

int		fts_getchar(char c[8])
{
	int	i;
	int	rd;

	if ((rd = read(0, c, 8)) == -1)
		ft_exit("read_error", EXIT_FAILURE); //TEMP
	if (rd == 1 && (c[0] > 31 || ft_strchr(INPUT_CONTROL_CHARS, c[0])))
		return (c[0]);
	else if (rd > 1)
	{
		i = -1;
		while (g_multibyte_chars[++i])
		{
			if (!ft_strcmp(g_multibyte_chars[i], c))
				return (i + 11);
		}
	}
	return (0);
}
