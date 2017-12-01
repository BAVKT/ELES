/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 02:24:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/01 20:20:46 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Return the amount of elements in the dir
*/

int		len_dirent(t_dir *dir)
{
            ft_putendlcolor("len_dirent();", MAGENTA);
	dir->len = 0;
	if(!(dir->rep = opendir(dir->path)))
		return(0);
	while ((dir->dirent = readdir(dir->rep)))
		dir->len++;
	closedir(dir->rep);
	return (dir->len);
}

/*
** Return the nb of spaces needed for the int in arg
*/

int		int_space(int nb)
{
            // ft_putendlcolor("int_space();", MAGENTA);
	return (ft_strlen(ft_itoa(nb)));
}

/*
** Init stat
*/

int		get_stat(t_dir *dir, char *name, int i)
{
		// ft_putendlcolor("get_stat();", MAGENTA);
	// if (check_path(name) == 2)
		dir->file_path = get_file_path(dir->path, name);
	if (check_path(name) != 2 && search_tab(g_b.paths, name))
		dir->file_path = ft_strjoin("./", name);
	if (lstat(dir->file_path, &dir->stat) == -1)
	{
		if (i)
			perror("");
		return (0);
	}
	return (1);
}

/*
** Return a tab with the good number of spaces for each
*/

int		*get_spaces(t_dir *dir)
{
            ft_putendlcolor("get_spaces();", MAGENTA);
	int	i;
	int	*tab;
	int nb;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * 8)))
		perror("MALLOC FAILED");
	while (i < 8)
		tab[i++] = 0;
	i = 0;
	while (dir->names[i])
	{
		if (get_stat(dir, dir->names[i], 0))
		{
			tab[0] = ((nb = ft_strlen(mode(dir))) > tab[0]) ? nb + 1 : tab[0];
			tab[1] = ((nb = int_space(dir->stat.st_nlink)) > tab[1]) ? nb : tab[1];
			tab[2] = ((nb = ft_strlen(owner(dir))) > tab[2]) ? nb + 1 : tab[2];
			tab[3] = ((nb = ft_strlen(gid(dir))) > tab[3]) ? nb : tab[3];
			tab[4] = ((nb = int_space(dir->stat.st_size)) > tab[4]) ? nb : tab[4];
			tab[5] = ((nb = ft_strlen(mtime(dir))) > tab[5]) ? nb : tab[5];
			tab[6] = ((nb = int_space(major(dir->stat.st_rdev)))) > tab[6] ? nb : tab[6];
			tab[7] = ((nb = int_space(minor(dir->stat.st_rdev)))) > tab[7] ? nb : tab[7];
		}
		i++;
	}
	return (tab);
}

/*
** Join the path and the name of file to get the path_file for stat
*/

char	*get_file_path(char *path, char *name)
{
            // ft_putendlcolor("get_file_path();", MAGENTA);
	char	*tmp;

	if (!ft_strcmp(path, "."))
		return(name);
	tmp = ft_strdup(path);
	if (tmp[ft_strlen(path) != '/'])
		tmp = ft_strjoin(path, "/");
	tmp = ft_strjoin(tmp, name);
	return (tmp);
}

/*
** If path is a file display it and return (1)
*/

int		display_file(t_dir *dir)
{
            ft_putendlcolor("display_file()", MAGENTA);
	int		ok;
	char	*c;

	if (!(dir->names = (char **)malloc(sizeof(char *) * 2)))
		perror("MALLOC FAILED");
	ok = check_path(dir->path);
	if (ok > 0 && ok != 2)
	{
		if (!(c = ft_strrchr(dir->path, '/')))
		{
			dir->names[0] = dir->path;
			dir->names[1] = NULL;
		}
		else
		{
			if (c + 1 == '\0')
				*c = '\0';
			c = ft_strrchr(dir->path, '/');
			dir->names[0] = ft_strdup(c + 1);
			dir->names[1] = NULL;
		}
		// *c = '\0';
		if (ft_strchr(g_b.options, 'l'))
			opt_l(dir);
		else
			ft_putendl(dir->names[0]);
		return (1);
	}
	return (0);
}

/*
** Display the final tab
*/

void	display(t_dir *dir)
{
            ft_putendlcolor("display()", MAGENTA);
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = tab_len(dir->display);
	if (ft_strchr(g_b.options, 'R'))
	{
		tmp = ft_strdup(dir->path);
		tmp[ft_strlen(dir->path) - 1] = ':';
		ft_putendl(tmp);
	}
	while (i < j)
		ft_putendl(dir->display[i++]);
}

/*
** return the color for display
*/

char	*get_color(char *path)
{
            // ft_putendlcolor("get_color();", MAGENTA);
	int		ok;
	char	*color;

	ok = check_path(path);
	if (ok == 1)
		color = ft_strdup("\x1b[37m");
	else if (ok == 2)
		color = ft_strdup("\x1b[36m");
	else if (ok == 3)
		color = ft_strdup("\x1b[35m");
	else
		color = ft_strdup("\x1b[33m");
	return (color);
}

/*
** Color for -l option
*/

void	l_color(t_dir *dir, int i)
{
            // ft_putendlcolor("l_color();", MAGENTA);
	char	*color;

	if (!ft_strchr(dir->names[i], '/') && search_tab(g_b.paths, dir->names[i]))
		dir->file_path = ft_strjoin("./", dir->names[i]);
	else
		dir->file_path = get_file_path(dir->path, dir->names[i]);
	color = get_color(dir->file_path);
	ft_putendlcolor(name(dir, i), color);
	ft_strdel(&color);
}

/*
** Display but with incredibly beautiful colors
*/

void	display_color(t_dir *dir)
{
            ft_putendlcolor("display_color();", MAGENTA);
	int		i;
	int		j;
	char	*tmp;

	j = tab_len(dir->display);
	if (!check_point(dir->path))
	{
		tmp = ft_strdup(dir->path);
		tmp[ft_strlen(dir->path)] = ':';
		dir->path[ft_strlen(dir->path)] = '\0';
	}
	if (ft_strcmp(dir->path, "."))
	{
		ft_putchar('\n');
		ft_putstr(dir->path);
		ft_putcharendl(':');
	}
	i = -1;
	while (++i < j)
	{
		dir->file_path = get_file_path(dir->path, dir->names[i]);
		tmp = get_color(dir->file_path);
		(check_path(dir->file_path) == 3) ? ft_putendlcolor(dir->names[i], MAGENTA) : ft_putendlcolor(dir->names[i], tmp);
		ft_strdel(&tmp);
	}
}
