/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_interface.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:47:42 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/24 16:42:42 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include "t_ftsdata.h"
#include "libft.h"
#include "c_colors.h"
#include "terminal_mode.h"

char const	g_spaces[256] = {[0 ... 254] = ' ', [255] = '\0'};

static void	print_separators(t_ftsprint *ftsp)
{
	int	x;
	int	y;

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

static void	print_status_bar(t_ftsdata *ftsd, t_ftsprint *ftsp)
{
	int	width;
	int	len;

	tputs(tgoto(ftsp->termcaps[TC_CM], 0, ftsd->term_h - 1), 1, tputchar);
	if ((width = ftsd->term_w % 255))
		ft_dprintf(0, C_REVERSE "%.*s" C_NO_REVERSE, width, g_spaces);
	width = ftsd->term_w - width;
	while (width)
	{
		ft_dprintf(0, C_REVERSE "%.*s" C_NO_REVERSE, width, g_spaces);
		width -= 255;
	}
	tputs(tgoto(ftsp->termcaps[TC_CM], 1, ftsd->term_h - 1), 1, tputchar);
	if (ftsd->search && ftsd->s_valid)
		ft_dprintf(0, C_REVERSE "%s" C_NO_REVERSE, ftsd->search);
	else if (ftsd->search)
		ft_dprintf(0, C_BG_RED "%s" C_RESET, ftsd->search);
	if ((len = ft_intlen(ftsd->list_size)) > 0
		&& len <= (ftsd->term_w - ftsp->elem_size - 3))
	{
		tputs(tgoto(ftsp->termcaps[TC_CM], ftsd->term_w - len - 1,
			ftsd->term_h - 1), 1, tputchar);
		ft_dprintf(0, C_REVERSE "%d" C_NO_REVERSE, ftsd->list_size);
	}
}

void	print_interface(t_ftsdata *ftsd, t_ftsprint *ftsp)
{
	if (ftsp->separators)
		print_separators(ftsp);
	if (ftsp->status_bar)
		print_status_bar(ftsd, ftsp);
}
