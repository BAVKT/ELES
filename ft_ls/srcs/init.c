/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 02:43:29 by vmercadi          #+#    #+#             */
/*   Updated: 2017/11/26 17:20:03 by vmercadi         ###   ########.fr       */
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
** Return the nb of paths that are dir
*/

int		get_nb()
{
            ft_putendlcolor("get_nb();", MAGENTA);
	int	nb;
	int	i;

	nb = 0;
	i = -1;
	while (g_b.paths[++i])
		nb += (check_path(g_b.paths[i]) == 2) ? 1 : 0;
	return (nb);
}

/*
** Init a new char* tab and set the size + 1 to NULL
*/

char	**tab_new(int size)
{
            ft_putendlcolor("tabnew();", MAGENTA);
	char	**tab;
	int		i;

	i = 0;
	if (size <= 0)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * size + 1)))
		perror("MALLOC FAILED");
	while (i < size)
		tab[i++] = ft_strnew(0);
	tab[i] = NULL;
	return (tab);
}

/*
** Fill the dir tab
*/

char	**tabdir()
{
            ft_putendlcolor("tabdir();", MAGENTA);
	char **tab;
	int i;
	int nb;

	i = -1;
	nb = 0;
	while (g_b.paths[++i])
	{
		if (check_path(g_b.paths[i]) != 2)
			;
		else
			nb++;
	}
	if (!(tab = tab_new(nb)))
		return (NULL);
	i = -1;
	nb = 0;
	while (g_b.paths[++i])
	{
		if (check_path(g_b.paths[i]) != 2)
			;
		else
			tab[nb++] = ft_strdup(g_b.paths[i]);
	}
	return (tab);
}

/*
** Fill the file tab
*/

char	**tabfile()
{
            ft_putendlcolor("tabfile();", MAGENTA);
	char **tab;
	int i;
	int nb;

	i = -1;
	nb = 0;
	while (g_b.paths[++i])
	{
		if (check_path(g_b.paths[i]) == -1 || check_path(g_b.paths[i]) == 2)
			;
		else
			nb++;
	}
	if (!(tab = tab_new(nb)))
		return (NULL);
	i = -1;
	nb = 0;
	while (g_b.paths[++i])
	{
		if (check_path(g_b.paths[i]) == -1 || check_path(g_b.paths[i]) == 2)
			;
		else
			tab[nb++] = ft_strdup(g_b.paths[i]);
	}
	return (tab);
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
** Sort a tab by ASCII
*/

char	**sort_ascii(char **tab)
{
            ft_putendlcolor("sort_ascii();", MAGENTA);
	int	k;
	int	ok;

	k = 0;
	ok = 0;
	if (!tab)
		return (NULL);
	while (tab[k + 1])
	{
		if (ft_strcmp(tab[k], tab[k + 1]) > 0)
		{
			swaaap(&tab[k], &tab[k + 1]);
			k = 0;
		}
		k++;
		if (!tab[k + 1] && !ok)
		{
			k = 0;
			ok = 1;
		}
	}
	tab[k + 1] = NULL;
	return (tab);
}

/*
** Merge 2 tab in one other
*/

char	**merge_tab(char **one, char **two)
{
            ft_putendlcolor("merge_tab();", MAGENTA);
	char	**tab;
	int		i;
	int		j;

	if (!two && !one)
		return (NULL);
	else if (!one && two)
	{
				// ft_putendl("YAAAA");
				// ft_putendl(two[0]);
				// ft_putstr("tablen = ");
				ft_putnbrendl(tab_len(two));
		if (tab_len(two) == 1 && !ft_strcmp(two[0], "."))
		{
			tab = tab_new(1);
			tab[0] = ft_strdup(".");
				// ft_putendl("NIKTOA");
				// ft_print_tab(tab);
			return (tab);
		}
		return (two);
	}
	else if (!two && one)
		return (one);
	tab = tab_new(tab_len(one) + tab_len(two));
	i = 0;
	j = 0;
			// ft_putendl("YOLO");
	while (one[j])
		tab[i++] = ft_strdup(one[j++]);
	j = 0;
	while (two[j])
		tab[i++] = ft_strdup(two[j++]);
	tab[i] = NULL;
			// ft_print_tab(tab);
	return (tab);
}

void	tri_path()
{
            ft_putendlcolor("tri_paths();", MAGENTA);
	char	**tab_dir;
	char	**tab_file;

	tab_dir = tabdir();
	tab_dir = sort_ascii(tab_dir);
	tab_file = tabfile();
	tab_file = sort_ascii(tab_file);
			// ft_putendl("yoooo");
			// ft_print_tab(tab_dir);
	if (g_b.paths)
		free_tab((void **)g_b.paths);
	g_b.paths = merge_tab(tab_file, tab_dir);
			// ft_putendl("vfrolich99999999");
			// ft_print_tab(g_b.paths);
	if (tab_file)
		free_tab((void **)tab_file);
	if (tab_dir)
		free_tab((void **)tab_dir);
			ft_putendl("yooo999999999");
			ft_print_tab(g_b.paths);
			ft_putendl("NIK");
}

void	tri()
{
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
	tri();
	// tri_path();
}











