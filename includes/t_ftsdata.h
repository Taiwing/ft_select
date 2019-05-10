/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ftsdata.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 11:39:06 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/10 16:39:52 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FTSDATA_H
# define T_FTSDATA_H

# define FTST_NBR		12
# define FG				0
# define BG				1

enum					e_ftstype {FTST_UNKNOWN = 0, FTST_DIR, FTST_LNK,
						FTST_SOCK, FTST_FIFO, FTST_EXEC, FTST_BLK, FTST_CHR,
						FTST_EXEC_UID, FTST_EXEC_GID, FTST_DIR_WO_STICKY,
						FTST_DIR_WO_NO_STICKY};

typedef struct			s_ftselem
{
	int					selected;
	int					type;
	const char			*str;
	struct s_ftselem	*prev;
	struct s_ftselem	*next;
}						t_ftselem;

# define TERMC			5

enum					e_terms {TC_CM = 0, TC_TI, TC_TE, TC_VI, TC_VE};

typedef struct			s_ftsprint
{
	char				*termcaps[TERMC];	/*termcpas needed for ft_select*/
	char				*lscolors;			/*env variable LSCOLORS*/
	char				colors[FTST_NBR][2][16];	/*colors for each type*/
	int					scroll;				/*number of lines used*/
	int					origin[2];			/*coordinates of the first word*/
	int					grid_h;				/*grid height*/
	int					grid_w;				/*grid width*/
	int					printable;			/*grid_h * grid_w*/
	t_ftselem			*from;				/*element to reprint*/
	int					from_pos[2];		/*coordinates of from*/
	int					cursor[2];			/*cursor pos in the grid (orig 0)*/
}						t_ftsprint;

enum					e_xy {X = 0, Y = 1};

typedef struct			s_ftsdata
{
	int					term_proc;
	int					term_h;
	int					term_w;
	int					elem_size;			/*size of a word*/
	int					list_size;			/*number of elements*/
	t_ftselem			*lst;				/*is the list and the cursor*/
	t_ftsprint			ftsp;				/*printing data*/
}						t_ftsdata;

#endif
