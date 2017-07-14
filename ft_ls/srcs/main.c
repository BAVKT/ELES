/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 00:55:02 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/08 05:39:52 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** ls de base
*/

void	ls()
{
            ft_putstrcolor("ls();", MAGENTA);
			// ft_putendl(g_d.path);	
	g_d.rep = opendir(g_d.path);
	while ((g_d.dirent = readdir(g_d.rep)))
	{
		if (g_d.dirent->d_name[0] != '.')
		{
			ft_putstr(g_d.dirent->d_name);
			ft_putstr("    ");
		}
	}
	ft_putchar('\n');
	closedir(g_d.rep);
}

/*
** Split and activation of the opts
*/
/*
void	opts(char **opt)
{
	
	if (ft_strstr());
}
*/

int		main(int ac, char **av)
{
	int		i;

	(void)ac;
	i = 0;
	init_base(av);
	init_dir();
	while (g_b.paths[i])
	{
		g_d.path = ft_strdup(g_b.paths[i++]);
		ls();
	}
	print();
	return (0);
}
