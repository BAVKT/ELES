/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 02:24:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/08 05:39:52 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
