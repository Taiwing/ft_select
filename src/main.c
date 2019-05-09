/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:37:28 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/09 12:10:10 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fts_init.h"
#include "fts_load_argv.h"
#include "fts_print.h"

int		main(int argc, char **argv)
{
	t_ftsdata	ftsd;

	(void)argc;
	ft_bzero((void *)&ftsd, sizeof(t_ftsdata));
	fts_init(&ftsd);
	fts_load_argv(&ftsd, argv);
	fts_print(&ftsd);
//	while (fts_input(&ftsd))
//		;
	ft_exit(NULL, EXIT_SUCCESS);
	return (0);
}
