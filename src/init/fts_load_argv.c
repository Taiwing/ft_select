/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_load_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:57:05 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/22 10:46:39 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/syslimits.h>
#include <sys/stat.h>
#include "ring.h"
#include "libft.h"

static char	*get_current_wd(char path[PATH_MAX])
{
	if (!getcwd(path, PATH_MAX))
		path[0] = 0;
	return (ft_strchr(path, 0));
}

static int	check_reg_file(mode_t mode)
{
	if (!(mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
		return (FTST_UNKNOWN);
	else if (mode & S_ISUID)
		return (FTST_EXEC_UID);
	else if (mode & S_ISGID)
		return (FTST_EXEC_GID);
	return (FTST_EXEC);
}

static int	check_dir(mode_t mode)
{
	if (!(mode & S_IWOTH))
		return (FTST_DIR);
	else if (mode & S_ISVTX)
		return (FTST_DIR_WO_STICKY);
	return (FTST_DIR_WO_NO_STICKY);
}

static int	check_type(char *name, char path[PATH_MAX])
{
	struct stat	st;
	char		*file;
	mode_t		type;

	file = name[0] != '/' && ft_strlen(path) + 1 + ft_strlen(name) < PATH_MAX ?
		ft_strcat(ft_strcat(path, "/"), name) : name;
	if (!lstat(file, &st))
	{
		type = st.st_mode & S_IFMT;
		if (type == S_IFREG)
			return (check_reg_file(st.st_mode));
		else if (type == S_IFDIR)
			return (check_dir(st.st_mode));
		else if (type == S_IFLNK)
			return (FTST_LNK);
		else if (type == S_IFSOCK)
			return (FTST_SOCK);
		else if (type == S_IFIFO)
			return (FTST_FIFO);
		else if (type == S_IFBLK)
			return (FTST_BLK);
		else if (type == S_IFCHR)
			return (FTST_CHR);
	}
	return (FTST_UNKNOWN);
}

/*TODO: get types of arguments (check if they are a file) if lscolors*/ 
void		fts_load_argv(t_ftsdata *ftsd, char **argv)
{
	int			l;
	t_ftselem	*first;
	char		path[PATH_MAX];
	char		*fp;

	fp = get_current_wd(path);
	while (*++argv)
	{
		ring_add(&ftsd->lst, *argv);
		if ((l = ft_strlen(*argv)) > ftsd->ftsp.elem_size)
			ftsd->ftsp.elem_size = l;
		if (ftsd->ftsp.lscolors)
			ftsd->lst->type = check_type(*argv, path);
		fp[0] = 0;
		++ftsd->list_size;
	}
	first = ftsd->lst;
	while (first && first->prev)
		first = first->prev;
	if (first)
	{
		first->prev = ftsd->lst;
		ftsd->lst->next = first;
		ftsd->lst = first;
	}
}
