/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 02:43:29 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/01 20:28:23 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Init the dir struct
*/

void	init_base(char **av)
{
            ft_putendlcolor("init_base();", MAGENTA);
	int		i;
	int		ok;

	i = 0;
	while (i < tab_len(av))
		g_b.paths[i++] = NULL;
	i = 0;
	ok = 0;
	while (av[++i])
	{
		if (!check_path(av[i]) && av[i][0] != '-')
		{
			ok = 1;
			g_b.paths[0] = NULL;
			break ;
		}
	}
	if (ok == 0)
	{
		g_b.paths[0] = ft_strdup(".");
		g_b.paths[1] = NULL;
	}
	set_paths(av);
	g_b.options = opt_tab(av);
	g_b.nbpaths = tab_len(g_b.paths);
}

/*
** Init somes of the dir struct values (len, path, tab_dir)
*/

void	init_dir(t_dir *dir, char *path)
{
            ft_putendlcolor("init_dir();", MAGENTA);
	int i;

    if (!path)
    	return ;
    dir->path = ft_strdup(path);
	len_dirent(dir);
	if (!(dir->dir_tab = (char **)malloc(sizeof(char *) * (dir->len + 1))))
		perror("MALLOC FAILED");
	i = 0;
	while (i < dir->len + 1)
		dir->dir_tab[i++] = NULL;
	if (check_path(dir->path) == 2)
		get_dir_tab(dir);
	else
		dir->dir_tab = NULL;
}

/*
** Set the dir_tab
*/

void	get_dir_tab(t_dir *dir)
{
            ft_putendlcolor("get_dir_tab();", MAGENTA);
	int	i;

	i = 0;
	if(!(dir->rep = opendir(dir->path)))
	{
		error((ft_strrchr(dir->path, '/')) + 1, 2);
		dir->dir_tab[i] = NULL;
		return ;
	}
	while ((dir->dirent = readdir(dir->rep)))
	{
		get_stat(dir, dir->dirent->d_name, 0);
		if (check_path(dir->file_path) == 2)
		{
			if (ft_strchr(g_b.options, 'a') && !check_point(dir->dirent->d_name))
				dir->dir_tab[i++] = ft_strdup(dir->dirent->d_name);
			else if (dir->dirent->d_name[0] != '.')
				dir->dir_tab[i++] = ft_strdup(dir->dirent->d_name);
		}
	}
	closedir(dir->rep);
	dir->dir_tab[i] = NULL;
}

/*
** Fill the names tab without the -a option
*/

void	get_names(t_dir *dir)
{
            ft_putendlcolor("get_names();", MAGENTA);
	int	i;

	i = 0;
    dir->names = (char **)malloc(sizeof(char *) * (dir->len + 1));
	dir->rep = opendir(dir->path);
	while ((dir->dirent = readdir(dir->rep)))
	{
		if (dir->dirent->d_name[0] != '.')
			dir->names[i++] = ft_strdup(dir->dirent->d_name);
	}
	dir->names[i] = NULL;
	closedir(dir->rep);
	i = tab_len(dir->names);
    dir->display = (char **)malloc(sizeof(char *) * (i + 1));
    dir->display = ft_cp_tab(dir->display, dir->names);
}

/*
** Normal swap but working one
*/

void	swaaap(char **a, char **b)
{
			// ft_putendlcolor("swaaaap();", MAGENTA);
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

/*
** Sort the paths in ascii order, files in first then directories
*/

void	tri_paths()
{
            ft_putendlcolor("tri_paths();", MAGENTA);
	int	i;
	int k;

	i = -1;
	while (g_b.paths[++i + 1])
	{
		if (check_path(g_b.paths[i]) == 2 && check_path(g_b.paths[i + 1]) != 2)
		{
			swaaap(&g_b.paths[i], &g_b.paths[i + 1]);
			i = -1;
		}
	}
	i = -1;
	while (g_b.paths[++i + 1] && check_path(g_b.paths[i + 1]) != 2)
	{
		if (ft_strcmp(g_b.paths[i], g_b.paths[i + 1]) > 0)
		{
			swaaap(&g_b.paths[i], &g_b.paths[i + 1]);
			i = -1;
		}
	}
	k = i;
	while (g_b.paths[++i + 1] && check_path(g_b.paths[i + 1]) == 2)
	{
		if (ft_strcmp(g_b.paths[i], g_b.paths[i + 1]) > 0)
		{
			swaaap(&g_b.paths[i], &g_b.paths[i + 1]);
			i = k;
		}
	}
}

/*
** Fill the paths tab
*/

void	set_paths(char **av)
{
            ft_putendlcolor("set_paths();", MAGENTA);
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (!av[i])
		return ;
	if (av[1][0] == '-')
		i++;
	while (av[i])
	{
		if (!check_path(av[i]))
			error_path(av[i++]);
		else
			g_b.paths[j++] = ft_strdup(av[i++]);
	}
	g_b.paths[j + 1] = NULL;
	tri_paths();
}











