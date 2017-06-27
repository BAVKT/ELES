/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 00:55:02 by vmercadi          #+#    #+#             */
/*   Updated: 2017/06/27 02:56:32 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

/*
** ls de base
*/

void	ft_ls()
{
	while ((g_b.dirent = readdir(g_b.rep)))
	{
		ft_putstr(g_b.dirent->d_name);
		ft_putstr("    ");
	}
	closedir(g_b.rep);
}

int		main()
{
	init_base();
	ft_ls();
	ft_putnbrendl(len_dirent((g_b.dirent)));
	return (0);
}