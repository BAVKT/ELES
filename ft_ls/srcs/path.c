/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 01:03:24 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/08 05:39:55 by vmercadi         ###   ########.fr       */
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
				i++;
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