/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 02:24:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/07 06:12:53 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Fill the paths tab
*/

void	set_paths(char **av)
{
			ft_putendl("set_paths();");
	int		i;
	int		j;

	i = 1;
	j = 0;
	g_b.nbpaths = 0;
	g_b.paths = (char**)malloc(sizeof(char*));
	g_b.paths[0] = ft_strdup(".");
	g_b.paths[1] = NULL;
	g_d.path = g_b.paths[0];
	if (!av[i])
		return ;
	while (av[i])
	{
		if (av[i][0] == '-')
			i++;
		else
		{
			if (!check_path(av[i]))
				;
			else
			{
				g_b.nbpaths++;
				g_b.paths[j++] = ft_strdup(av[i++]);
			}
		}
	}
	g_b.paths[j] = NULL;
	g_d.path = g_b.paths[0];
}

/*
** Retourne le nombre d'éléments existants dans dirent.
*/

int		len_dirent()
{
			ft_putendl("len_dirent();");
	int	i;

	i = 0;
	g_d.rep = opendir(g_d.path);
	while ((g_d.dirent = readdir(g_d.rep)))
		i++;
	closedir(g_d.rep);
	return (i);
}
