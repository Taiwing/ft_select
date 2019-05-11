/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:37:28 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/11 13:04:05 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fts_init.h"
#include "fts_load_argv.h"
#include "fts_print.h"
#include "charfunc.h"

int		main(int argc, char **argv)
{
	t_ftsdata	ftsd;
	char		input[8];

	(void)argc;
	ft_bzero((void *)&ftsd, sizeof(t_ftsdata));
	fts_init(&ftsd);
	fts_load_argv(&ftsd, argv);
	fts_print(&ftsd);
	while (ftsd.lst && g_charfunc[fts_getchar(input)](&ftsd, input))
	{
		ft_bzero(input, 8);
		fts_print(&ftsd);
	}
	ft_atexit(NULL);
	ft_heap_collector(NULL, FT_COLLEC_FREE);
	return (0);
}
