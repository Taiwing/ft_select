/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ftsdata.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 11:39:06 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/05 13:45:38 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FTSDATA_H
# define T_FTSDATA_H

enum					e_ftstype {FTST_DIR = 0, FTST_LNK, FTST_SOCK, FTST_FIFO,
						FTST_EXEC, FTST_BLK, FTST_CHR, FTST_EXEC_UID,
						FTST_EXEC_GID, FTST_DIR_WO_STICKY,
						FTST_DIR_WO_NO_STICKY};

typedef struct			s_ftselem
{
	int					selected;
	int					type;
	char				*str;
	struct s_ftselem	*prev;
	struct s_ftselem	*next;
}						t_ftselem;

enum					e_xy {X = 0, Y = 1};

typedef struct			s_ftsdata
{
	int					term_h;
	int					term_w;
	int					scroll;			/*number of lines needed*/
	int					line_w;			/*number of element per line*/
	int					elem_size;		/*size of a word*/
	int					origin[2];		/*coordinates of the first word*/
	int					cursor;			/*index of selection in the list*/
	int					list_size;		/*number of elements*/
	char				*lscolors;		/*env variable LSCOLORS*/
}						t_ftsdata;

#endif
