/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:08:55 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/14 11:10:45 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wtlen(char **wt)
{
	int	len;

	len = -1;
	while (wt[++len])
		;
	return (len);
}
