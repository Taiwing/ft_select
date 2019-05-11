/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:09:26 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/11 10:26:35 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_ftsdata.h"
#include "c_colors.h"

static char	*get_color(char c, int fbg)
{
	c = c > 64 && c < 91 ? c + 32 : c;
	if (c == 'a')
		return (fbg == FG ? C_FG_BLACK : C_BG_BLACK);
	if (c == 'b')
		return (fbg == FG ? C_FG_RED : C_BG_RED);
	if (c == 'c')
		return (fbg == FG ? C_FG_GREEN : C_BG_GREEN);
	if (c == 'd')
		return (fbg == FG ? C_FG_YELLOW : C_BG_YELLOW);
	if (c == 'e')
		return (fbg == FG ? C_FG_BLUE : C_BG_BLUE);
	if (c == 'f')
		return (fbg == FG ? C_FG_MAGENTA : C_BG_MAGENTA);
	if (c == 'g')
		return (fbg == FG ? C_FG_CYAN : C_BG_CYAN);
	if (c == 'h')
		return (fbg == FG ? C_FG_WHITE : C_BG_WHITE);
	else
		return (fbg == FG ? C_FG_DEFAULT : C_BG_DEFAULT);
}

void		load_colors(char *lscolors, char colors[FTST_NBR][2][16])
{
	int		i;
	int		j;
	int		len;
	char	buf[23];

	len = 0;
	buf[0] = 0;
	if (lscolors)
		ft_strncpy(buf, lscolors, 23);
	if (!lscolors || (len = ft_strlen(lscolors)) < 22)
		ft_strncat(buf, "xxxxxxxxxxxxxxxxxxxxxx", 22 - len);
	lscolors = buf;
	i = 0;
	ft_strcpy(colors[FTST_UNKNOWN][FG], get_color('x', FG));
	ft_strcpy(colors[FTST_UNKNOWN][BG], get_color('x', BG));
	while (++i < FTST_NBR && *lscolors)
	{
		j = i % 2 ? BG : FG;
		ft_strcpy(colors[i][j], get_color(*lscolors, j));
		if (*lscolors > 64 && *lscolors < 91)
			ft_strcat(colors[i][j], C_BOLD);
		++lscolors;
	}
}
