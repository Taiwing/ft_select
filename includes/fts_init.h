/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:31:58 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/09 11:54:29 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTS_INIT_H
# define FTS_INIT_H

# include "t_ftsdata.h"

t_ftsdata	*ftsd_container(t_ftsdata *ftsd_in);
void		init_termcaps(t_ftsdata *ftsd);
void		get_term_size(t_ftsdata *ftsd);
void		fts_init(t_ftsdata *ftsd);

#endif
