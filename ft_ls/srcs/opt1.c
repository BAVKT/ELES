/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:32:27 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/08 05:39:53 by vmercadi         ###   ########.fr       */
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
** -a Option
*/

void	opt_a()
{
            ft_putstrcolor("opt_a();", MAGENTA);
	g_d.rep = opendir(g_d.path);
	while ((g_d.dirent = readdir(g_d.rep)))
	{
		ft_putstr(g_d.dirent->d_name);
		ft_putstr("    ");
	}
	closedir(g_d.rep);
}

/*
** -R option
*/

void	opt_R()
{
			ft_putendl("opt_R();");
	return ;
}