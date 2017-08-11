/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 02:24:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/11 16:44:54 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Free a char**
*/

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	ft_memdel((void**)tab);
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
** Swap 2 char*
*/

void	swap_tab(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

/*
** donne le nombre de str dans un char**
*/

int		tab_len(char **tab)
{
            ft_putendlcolor("tab_len();", MAGENTA);
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

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