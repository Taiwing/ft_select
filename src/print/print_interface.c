/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_interface.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:47:42 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/23 12:06:33 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include "t_ftsdata.h"
#include "libft.h"
#include "c_colors.h"
#include "terminal_mode.h"

void	print_interface(t_ftsdata *ftsd, t_ftsprint *ftsp)
{
	int	x;
	int	y;

	(void)ftsd;
	if (ftsp->separators)
	{
		y = 0;
		while (y < ftsp->grid_h)
		{
			x = 0;
			while (x < ftsp->grid_w + 1)
			{
				tputs(tgoto(ftsp->termcaps[TC_CM], ftsp->origin[X]
					+ (x * ftsp->col_w), y), 1, tputchar);
				ft_dprintf(0, C_REVERSE " " C_NO_REVERSE);
				++x;
			}
			++y;
		}
	}
}
