/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:32:27 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/25 21:48:42 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Fill tab with the differents options and check if they exists
*/

char	*opt_tab(char **av)
{
            ft_putstrcolor("opt_tab();", MAGENTA);
	int		i;
	int		j;
	int		k;
	char	*tab;

	i = 1;
	k = 0;
	tab = ft_strnew(5);
	while (av[i] && av[i][0] == '-')
	{
		j = 1;
		while (av[i][j])
		{
			if (av[i][j] != 'a' && av[i][j] != 'l' && av[i][j] != 'R' && 
			av[i][j] != 'r' && av[i][j] != 't')
				usage();
			else if (av[i][j])
				tab[k++] = av[i][j++];
		}
			i++;
	}
	return (tab);
}

/*
** -a Option	Show hidden files
*/

void	opt_a(t_dir *dir)
{
            ft_putstrcolor("opt_a();", MAGENTA);
	int	i;

	i = 0;
	dir->rep = opendir(dir->path);
	while ((dir->dirent = readdir(dir->rep)))
		dir->names[i++] = ft_strdup(dir->dirent->d_name);
	closedir(dir->rep);
	dir->names[i] = NULL;
    dir->display = (char **)malloc(sizeof(char *) * dir->len + 1);
    dir->display = ft_cp_tab(dir->display, dir->names, dir->len);
}

/*
** -t Option	Sort by time
*/

void	opt_t()
{

}

/*
** -r Option	Reverse the order
*/

void	opt_r()
{

}

/*
** -l Option	Give more detailled informations 
*/

void	opt_l()
{

}
