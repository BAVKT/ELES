/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 02:24:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/25 21:49:46 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** donne le nombre de str dans un char**
*/

int		tab_len(char **tab)
{
            ft_putstrcolor("tab_len();", MAGENTA);
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

/*
** Retourne le nombre d'éléments existants dans dirent.
*/

int		len_dirent(t_dir *dir)
{
            ft_putstrcolor("len_dirent();", MAGENTA);	
	dir->len = 0;
	dir->rep = opendir(dir->path);
	while ((dir->dirent = readdir(dir->rep)))
		dir->len++;
	closedir(dir->rep);
	return (dir->len);
}

/*
** Display the final tab
*/

void	display(t_dir *dir)
{
            ft_putstrcolor("display();", MAGENTA);
	int	i;
	int	j;

	i = 0;
	j = tab_len(dir->display);
	while (i < j)
	{
		ft_putstr(dir->display[i]);
		ft_putstr("    ");
		i++;
	}
	ft_putchar('\n');
}