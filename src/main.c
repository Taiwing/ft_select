/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:37:28 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/22 11:21:51 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fts_init.h"
#include "fts_load_argv.h"
#include "fts_print.h"
#include "charfunc.h"

static void	fts_print_selection(t_ftselem *lst, int size)
{
	t_ftselem	*ptr;

	if (!lst || !size)
		return ;
	ptr = lst;
	ft_printf("%s", ptr->str);
	while (ptr->next && ptr->next != lst)
	{
		ptr = ptr->next;
		ft_printf(" %s", ptr->str);
	}
}

int			main(int argc, char **argv)
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
	fts_print_selection(ftsd.lst, ftsd.list_size);
	ft_heap_collector(NULL, FT_COLLEC_FREE);
	return (0);
}
