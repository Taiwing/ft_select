/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:26:34 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/29 18:30:18 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "conversions.h"
#include "format_data.h"
#include "libft.h"

#ifdef NO_COLLEC

void	convert_alloc(t_pdata *data, t_farg *args, t_params *conv, char **fmt)
{
	t_pdata	loc_data;

	init_buf(&loc_data);
	if (ft_strchr("dbBouxX", conv->type))
		itoa_cast(&loc_data, args, conv);
	else if (ft_strchr("eEfFgG", conv->type))
		efg_conversions(&loc_data, args, conv);
	else if (conv->type == 'p' || conv->type == 'P')
		p_conversion(&loc_data, args, conv);
	else if (conv->type == 'c')
		c_conversion(&loc_data, args, conv);
	else if (conv->type == 'C')
		lc_conversion(&loc_data, args, conv);
	else if (conv->type == 's')
		s_conversion(&loc_data, args, conv);
	else if (conv->type == 'S')
		ls_conversion(&loc_data, args, conv);
	else if (conv->type == 't')
		t_conversion(&loc_data, args, conv, fmt);
	else
		add_to_buf(&loc_data, NULL, conv->type, 1);
	if (loc_data.n != -1)
		format_data_alloc(data, &loc_data, conv, 0);
	data->n = loc_data.n == -1 ? -1 : data->n;
	free(loc_data.abuf);
}

#else

void	convert_alloc(t_pdata *data, t_farg *args, t_params *conv, char **fmt)
{
	t_pdata	loc_data;

	init_buf(&loc_data);
	if (ft_strchr("dbBouxX", conv->type))
		itoa_cast(&loc_data, args, conv);
	else if (ft_strchr("eEfFgG", conv->type))
		efg_conversions(&loc_data, args, conv);
	else if (conv->type == 'p' || conv->type == 'P')
		p_conversion(&loc_data, args, conv);
	else if (conv->type == 'c')
		c_conversion(&loc_data, args, conv);
	else if (conv->type == 'C')
		lc_conversion(&loc_data, args, conv);
	else if (conv->type == 's')
		s_conversion(&loc_data, args, conv);
	else if (conv->type == 'S')
		ls_conversion(&loc_data, args, conv);
	else if (conv->type == 't')
		t_conversion(&loc_data, args, conv, fmt);
	else
		add_to_buf(&loc_data, NULL, conv->type, 1);
	if (loc_data.n != -1)
		format_data_alloc(data, &loc_data, conv, 0);
	data->n = loc_data.n == -1 ? -1 : data->n;
	free(ft_heap_collector(loc_data.abuf, FT_COLLEC_GET));
}

#endif
