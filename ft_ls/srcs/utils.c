/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 02:24:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/13 16:05:04 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Retourne le nombre d'éléments existants dans dirent.
*/

int		len_dirent(t_dir *dir)
{
            ft_putendlcolor("len_dirent();", MAGENTA);
	dir->len = 0;
	dir->rep = opendir(dir->path);
	while ((dir->dirent = readdir(dir->rep)))
		dir->len++;
	closedir(dir->rep);
	return (dir->len);
}

/*
** Return the size in spaces needed for the int in arg
*/

int		get_int_spaces(int nb)
{
            //ft_putendlcolor("get_int_spaces();", MAGENTA);
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
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
	tab = (int *)malloc(sizeof(int) * 6);
	while (i < 6)
		tab[i++] = 0;
	i = 0;
	while (dir->names[i])
	{
		dir->file_path = get_file_path(dir->path, dir->names[i]);
		stat(dir->file_path, &dir->stat);
		tab[0] = ((nb = ft_strlen(get_mode(dir))) > tab[0]) ? nb : tab[0];
		tab[1] = ((nb = get_int_spaces(dir->stat.st_nlink)) > tab[1]) ?
			nb : tab[1];
		tab[2] = ((nb = ft_strlen(get_owner(dir))) > tab[2]) ? nb : tab[2];
		tab[3] = ((nb = ft_strlen(get_gid(dir))) > tab[3]) ? nb : tab[3];
		tab[4] = ((nb = get_int_spaces(dir->stat.st_size)) > tab[4]) ?
			nb : tab[4];
		tab[5] = ((nb = ft_strlen(get_time(dir))) > tab[5]) ? nb : tab[5];
		i++;
	}
	return (tab);
}

/*
** Join the path and the name of file to get the path file for stat
*/

char	*get_file_path(char *path, char *name)
{
            //ft_putendlcolor("get_file_path();", MAGENTA);
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
** Display the final tab
*/

void	display(t_dir *dir)
{
            ft_putendlcolor("display();", MAGENTA);
	int	i;
	int	j;
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
		ft_putendl(dir->display[i]);
}

/*
** Display but with beautiful colors
*/

void	display_color(t_dir *dir)
{
            ft_putendlcolor("display_color();", MAGENTA);
	int		i;
	int		j;
	int		ok;
	char	*tmp;

	i = 0;
	j = tab_len(dir->display);
	if (!check_point(dir->path))
	{
		tmp = ft_strdup(dir->path);
		tmp[ft_strlen(dir->path)] = ':';
		dir->path[ft_strlen(dir->path)] = '\0';
		ft_putendl(tmp);
	}
	while (i < j)
	{
		dir->file_path = get_file_path(dir->path, dir->names[i]);
		ok = check_path(dir->file_path);
		if (ok == 1)
			ft_putendl(dir->names[i]);
		else if (ok == 2)
			ft_putendlcolor(dir->names[i], CYAN);
		else if (ok == 3)
			ft_putendlcolor(dir->file_path, MAGENTA);
		i++;
	}
}