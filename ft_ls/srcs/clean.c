/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 17:55:07 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/13 19:38:15 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**
** AUCUN DE MARCHE
**
*/

/*
** Free all the elements from t_base 
*/

void	clean_base()
{
            ft_putendlcolor("clean_base();", MAGENTA);
	free_tab((void **)g_b.paths);
	ft_strdel(&g_b.options);
}

/*
** Free all the content of the t_dir
*/

void	clean_sdir(t_dir *dir)
{
            ft_putendlcolor("clean_sdir();", MAGENTA);
    int i;

    i = 0;
	dir->path ? ft_strdel(&dir->path) : i++;
	dir->file_path ? ft_strdel(&dir->file_path) : i++;
    	ft_putendl("pouet");
	free_tab((void **)dir->names);
	free_tab((void **)dir->display);
	free_tab((void **)dir->dir_tab);
}