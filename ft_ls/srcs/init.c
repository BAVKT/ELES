/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 02:43:29 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/08 05:39:53 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Init the dir struct
*/
void	init_base(char **av)
{
            ft_putstrcolor("init_base();", MAGENTA);
	int		i;

	i = 1;
	g_b.options = opt_tab(av);
	g_b.sdir = (t_dir *)malloc(sizeof(t_dir));
	g_b.sdir->next = NULL;
	set_paths(av);
}

/*
** Init the dir struct values
*/
void	init_dir()
{
            ft_putstrcolor("init_dir();", MAGENTA);
	if (g_d.path && !g_d.dirent)
	{
		g_d.rep = opendir(g_d.path);
		g_d.dirent = readdir(g_d.rep);
		closedir(g_d.rep);
		//g_d.tabdir = init_tab(g_d.len);
		g_d.len = len_dirent();
	}
}