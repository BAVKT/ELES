/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 16:31:40 by vmercadi          #+#    #+#             */
/*   Updated: 2017/11/23 22:18:47 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**  toutes les options bonus (pas obligé de les faire mais au moins c'est pret si jamais)
*/

/*
** Use the time of last access instead of last modification
*/

void	opt_u(t_dir *dir)
{
            ft_putendlcolor("opt_u();", MAGENTA);
	int	i;
	int	time;

	i = 0;
	while (dir->names[i + 1])
	{
		dir->file_path = get_file_path(dir->path, dir->names[i]);
		lstat(dir->file_path, &dir->stat);
		time = dir->stat.st_atime;
		dir->file_path = get_file_path(dir->path, dir->names[i + 1]);
		lstat(dir->file_path, &dir->stat);
		if (dir->stat.st_atime > time)
		{
			swap_tab((void **)&dir->names[i], (void **)&dir->names[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

/*
** Output is not sorted.  This option turns on the -a option
*/

void	opt_f()
{

}

/*
** Directories are listed as plain files (not searched recursively).
*/

void	opt_d()
{

}

/*
** For each file, print the file's file serial number (inode number).
*/

void	opt_i()
{

}

/*
** List in long format, but omit the group id.
*/

void	opt_o()
{

}
