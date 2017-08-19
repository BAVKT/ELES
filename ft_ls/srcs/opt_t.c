/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 18:55:34 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/19 19:11:48 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** -t Option	Sort by time
*/

void	opt_t(t_dir *dir)
{
            ft_putendlcolor("opt_t();", MAGENTA);
	int	i;
	int	time;

	i = 0;
	presort_time(dir, 15778800);
	presort_time(dir, 2629800);
	presort_time(dir, 657450);
	presort_time(dir, 93922);
	while (dir->names[i] && dir->names[i + 1])
	{
		dir->file_path = get_file_path(dir->path, dir->names[i]);
		lstat(dir->file_path, &dir->stat);
		time = dir->stat.st_mtime;
		dir->file_path = get_file_path(dir->path, dir->names[i + 1]);
		lstat(dir->file_path, &dir->stat);
		if (dir->stat.st_mtime > time)
		{
			swap_tab((void **)&dir->names[i], (void **)&dir->names[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

/*
** Make the -t option more powerfull. Cause at this moment, it's really shitty.
*/

void	presort_time(t_dir *dir, int ti)
{
            ft_putendlcolor("presort_time();", MAGENTA);
	char	**old;
	char	**tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	old = ft_init_tab(tab_len(dir->names) + 1);
	tmp = ft_init_tab(tab_len(dir->names) + 1);
	while(dir->names[i])
	{
		lstat(get_file_path(dir->path, dir->names[i]), &dir->stat);
		if ((time(NULL) - dir->stat.st_mtime > ti))
			old[j++] = ft_strdup(dir->names[i++]);
		else
			tmp[k++] = ft_strdup(dir->names[i++]);
	}
	free_tab((void **)dir->names);
	old[j] = NULL;
	i = 0;
	while (old[i] && tmp[k])
		tmp[k++] = ft_strdup(old[i++]);
	tmp[k] = NULL;
	dir->names = ft_cp_tab(dir->names, tmp);
}
