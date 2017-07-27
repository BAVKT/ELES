/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:32:27 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/27 22:08:19 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


/**
** PROBLEMES DANS BASIC_SORT
**	Et opt_r
** 	Trient mal
*/



/*
** Basic sort is lexicographique
*/

void	basic_sort(t_dir *dir)
{
            ft_putendlcolor("basic_sort();", MAGENTA);
	int		i;

	i = 0;
	while (dir->names[i + 1])
	{
		if (ft_strcmp(dir->names[i], dir->names[i + 1]) > 0)
		{
			swap_tab(&dir->names[i], &dir->names[i + 1]);
			i = 0;
		}
		i++;
	}
}

/*
** Fill tab with the differents options and check if they exists
*/

char	*opt_tab(char **av)
{
            ft_putendlcolor("opt_tab();", MAGENTA);
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	g_b.options = ft_strnew(5);
	while (av[i] && av[i][0] == '-')
	{
		j = 1;
		while (av[i][j])
		{
			if (av[i][j] != 'a' && av[i][j] != 'l' && av[i][j] != 'R' && 
			av[i][j] != 'r' && av[i][j] != 't')
				usage();
			else if (av[i][j])
				g_b.options[k++] = av[i][j++];
		}
			i++;
	}
	return (g_b.options);
}

/*
** -a Option	Show hidden files
*/

void	opt_a(t_dir *dir)
{
            ft_putendlcolor("opt_a();", MAGENTA);
	int	i;

	i = 0;
	dir->rep = opendir(dir->path);
    dir->names = (char **)malloc(sizeof(char *) * (dir->len + 1));
	while ((dir->dirent = readdir(dir->rep)))
		dir->names[i++] = ft_strdup(dir->dirent->d_name);
	closedir(dir->rep);
	dir->names[i] = NULL;
    dir->display = (char **)malloc(sizeof(char *) * dir->len + 1);
    dir->display = ft_cp_tab(dir->display, dir->names);
}

/*
** -t Option	Sort by time
*/

void	opt_t(t_dir *dir)
{
            ft_putendlcolor("opt_t();", MAGENTA);
	int	i;
	int	time;

	i = 0;
	while (dir->names[i])
	{
		dir->file_path = get_file_path(dir->path, dir->names[i]);
		stat(dir->file_path, &dir->stat);
		time = dir->stat.st_mtime;
		dir->file_path = get_file_path(dir->path, dir->names[i + 1]);
		stat(dir->file_path, &dir->stat);
		if (dir->stat.st_mtime > time)
		{
			swap_tab(&dir->names[i], &dir->names[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

/*
** -r Option	Reverse the order
*/

void	opt_r(t_dir *dir)
{
	char	**rev;
	int		i;
	int		x;

	i = 0;
	x = tab_len(dir->names);
	rev = (char **)malloc(sizeof(char *) * (x + 1));
	x -= 1 ; 
	while (dir->names[i])
	{
		rev[i] = ft_strdup(dir->names[x - i]);
		i++;
	}
	rev[i] = NULL;
	i = 0;
	while (rev[i])
	{
		ft_strdel(&dir->names[i]);
		dir->names[i] = ft_strdup(rev[i]);
		i++;
	}
	free_tab(rev);
}

/*
** -l Option	Give more detailled informations 
*/

void	opt_l()
{

}
