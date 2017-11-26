/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:32:27 by vmercadi          #+#    #+#             */
/*   Updated: 2017/11/26 16:42:36 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Basic sort is lexicographical and not case sensitive
*/

void	basic_sort(t_dir *dir)
{
            ft_putendlcolor("basic_sort();", MAGENTA);
	int	i;

	i = 0;
	if (!dir->names[0])
		return ;
	while (dir->names[i + 1])
	{
		if (ft_strcmp(dir->names[i], dir->names[i + 1]) > 0)
		{
			swap_tab((void **)&dir->names[i], (void **)&dir->names[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

/*
** Fill tab with the differents options and check if they exists
*/

char	*opt_tab(char **av)
{
            ft_putendlcolor("opt_tab();", MAGENTA);
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	g_b.options = ft_strnew(7);
	while (av[++i] && av[1][0] == '-')
	{
		if (av[i][0] == '-')
		{
			j = 1;
			while (av[i][j])
			{
				if (av[i][j] != 'a' && av[i][j] != 'l' && av[i][j] != 'R' &&
					av[i][j] != 'r' && av[i][j] != 't' && av[i][j] != '1' &&
					av[i][j] != 'u')
					usage();
				else if (av[i][j])
					g_b.options[k++] = av[i][j++];
			}
		}
	}
	return (g_b.options);
}

/*
** -a Option	Show hidden files & dirs
*/

void	opt_a(t_dir *dir)
{
            ft_putendlcolor("opt_a();", MAGENTA);
	int	i;

	if (!(dir->names = (char **)malloc(sizeof(char *) * (dir->len + 1))))
		perror("MALLOC FAILED");
	i = 0;
    while (i < dir->len + 1)
    	dir->names[i++] = NULL;
	i = 0;
	dir->rep = opendir(dir->path);
	while ((dir->dirent = readdir(dir->rep)))
		dir->names[i++] = ft_strdup(dir->dirent->d_name);
	dir->names[i] = NULL;
	closedir(dir->rep);
	if (!(dir->display = (char **)malloc(sizeof(char *) * dir->len + 1)))
		perror("MALLOC FAILED");
	dir->display = ft_cp_tab(dir->display, dir->names);
}

/*
** -r Option	Reverse the order
*/

void	opt_r(t_dir *dir)
{
            ft_putendlcolor("opt_r();", MAGENTA);
	char	**rev;
	int		i;
	int		x;

	i = 0;
	x = tab_len(dir->names);
	rev = (char **)malloc(sizeof(char *) * (x + 1));
	x -= 1;
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
	free_tab((void **)rev);
}

/*
** -R Option
*/

void	opt_R(t_dir *dir)
{
            ft_putendlcolor("opt_R();", MAGENTA);
	int i;

	i = 0;
	dir->names = ft_cp_tab(dir->names, dir->dir_tab);
	!ft_strchr(g_b.options, 't') ? i = 0 : opt_t(dir);
	!ft_strchr(g_b.options, 'r') ? i = 0 : opt_r(dir);
	dir->dir_tab = ft_cp_tab(dir->dir_tab, dir->names);
	while (dir->dir_tab && dir->dir_tab[i])
	{
		ft_putchar('\n');
		ft_putstr(get_file_path(dir->path, dir->dir_tab[i]));
		ft_putcharendl(':');
		ls(get_file_path(dir->path, dir->dir_tab[i++]));
	}
}
