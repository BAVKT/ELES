/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 02:43:29 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/07 06:09:44 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Init the dir struct
*/
void	init_base(char **av)
{
			ft_putendl("init_base();");
	int		i;

	i = 1;
	set_paths(av);
	g_b.options = opt_tab(av);
	g_b.sdir = (t_dir *)malloc(sizeof(t_dir));
	g_b.sdir->next = NULL;
}

/*
** Init the dir struct values
*/
void	init_dir()
{
			ft_putendl("init_dir();");

			ft_putendl("yo");
	g_d.rep = opendir(g_d.path);
			ft_putendl(g_d.path);
	g_d.dirent = readdir(g_d.rep);
	closedir(g_d.rep);
	//g_d.tabdir = init_tab(g_d.len);
	g_d.len = len_dirent();
}