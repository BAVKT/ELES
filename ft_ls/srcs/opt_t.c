/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 18:55:34 by vmercadi          #+#    #+#             */
/*   Updated: 2017/11/26 19:23:00 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	opt_t(t_dir *dir)
{
            ft_putendlcolor("opt_t();", MAGENTA);
	int		i;
	time_t	time;
	t_s		*tmp;

	i = 0;
	dir->s = (t_s *)malloc(sizeof(t_s));
	dir->s->next = NULL;
	tmp = dir->s;
	while (dir->names[i] && dir->names[i + 1])
	{
		store_stat(dir, tmp, dir->names[i]);
		tmp = dir->s;
		while (tmp->next && ft_strcmp(tmp->name, dir->names[i]))
			tmp = tmp->next;
		time = tmp->mtime;
		tmp = dir->s;
		while (tmp->next && ft_strcmp(tmp->name, dir->names[i + 1]))
			tmp = tmp->next;
		if (tmp->mtime > time)
		{
			swap_tab((void **)&dir->names[i], (void **)&dir->names[i + 1]);
			i = -1;
		}
		i++;
	}
}

void	store_stat(t_dir *dir, t_s *tmp, char *name)
{
		ft_putendlcolor("store_stat();", MAGENTA);
	get_stat(dir, name, 0);
	tmp->name = ft_strdup(name);
	tmp->dev = dir->stat.st_dev;
	tmp->ino = dir->stat.st_ino;
	tmp->mode = dir->stat.st_mode;
	tmp->nlink = dir->stat.st_nlink;
	tmp->uid = dir->stat.st_uid;
	tmp->gid = dir->stat.st_gid;
	tmp->rdev = dir->stat.st_rdev;
	tmp->size = dir->stat.st_size;
	tmp->blksize = dir->stat.st_blksize;
	tmp->blocks = dir->stat.st_blocks;
	tmp->atime = dir->stat.st_atime;
	tmp->mtime = dir->stat.st_mtime;
	tmp->ctime = dir->stat.st_ctime;
	if (!(tmp->next = (t_s *)malloc(sizeof(t_s))))
		perror("Malloc failed");
	tmp = tmp->next;
	tmp->next = NULL;
}

/*
** -t Option	Sort by time
*/

// void	opt_t(t_dir *dir)
// {
//             ft_putendlcolor("opt_t();", MAGENTA);
// 	int		i;
// 	time_t	time;
// 	t_s		*tmp;

// 	i = 0;
// 	dir->s = (t_s *)malloc(sizeof(t_s));
// 	tmp = dir->s;
// 	store_stat(dir);
// 	while (dir->names[i] && dir->names[i + 1])
// 	{
// 		tmp = dir->s;
// 		while (tmp->next && ft_strcmp(tmp->name, dir->names[i]))
// 			tmp = tmp->next;
// 		time = tmp->mtime;
// 		tmp = dir->s;
// 		while (tmp->next && ft_strcmp(tmp->name, dir->names[i + 1]))
// 			tmp = tmp->next;
// 		if (tmp->mtime > time)
// 		{
// 			swap_tab((void **)&dir->names[i], (void **)&dir->names[i + 1]);
// 			i = -1;
// 		}
// 		i++;
// 	}
// }

// ##################V2##################

// void	opt_t(t_dir *dir)
// {
//             ft_putendlcolor("opt_t();", MAGENTA);
// 	int		i;
// 	time_t	time;
// 	t_s		*tmp;
// 	t_s		*actual;

// 	i = 0;
// 	dir->s = (t_s *)malloc(sizeof(t_s));
// 	dir->s->next = NULL;
// 	tmp = dir->s;
// 	while (dir->names[i] && dir->names[i + 1])
// 	{
// 		store_stat(dir, tmp, dir->names[i]);
// 		tmp = dir->s;
// 		while (tmp->next && ft_strcmp(tmp->name, dir->names[i]))
// 			tmp = tmp->next;
// 		time = tmp->mtime;
// 		tmp = dir->s;
// 		while (tmp->next && ft_strcmp(tmp->name, dir->names[i + 1]))
// 			tmp = tmp->next;
// 		if (tmp->mtime > time)
// 		{
// 			swap_tab((void **)&dir->names[i], (void **)&dir->names[i + 1]);
// 			i = -1;
// 		}
// 		i++;
// 	}
// }

// void	store_stat(t_dir *dir, t_s *tmp, char *name)
// {
// 	ft_putendlcolor("store_stat();", MAGENTA);
// 	while ()
// 	get_stat(dir, name, 0);
// 	tmp->name = ft_strdup(name);
// 	tmp->dev = dir->stat.st_dev;
// 	tmp->ino = dir->stat.st_ino;
// 	tmp->mode = dir->stat.st_mode;
// 	tmp->nlink = dir->stat.st_nlink;
// 	tmp->uid = dir->stat.st_uid;
// 	tmp->gid = dir->stat.st_gid;
// 	tmp->rdev = dir->stat.st_rdev;
// 	tmp->size = dir->stat.st_size;
// 	tmp->blksize = dir->stat.st_blksize;
// 	tmp->blocks = dir->stat.st_blocks;
// 	tmp->atime = dir->stat.st_atime;
// 	tmp->mtime = dir->stat.st_mtime;
// 	tmp->ctime = dir->stat.st_ctime;
// 	if (!(tmp->next = (t_s *)malloc(sizeof(t_s))))
// 		perror("Malloc failed");
// 	tmp = tmp->next;
// 	tmp->next = NULL;
// }
// ###################V2###############
/*
** Store all the lists
*/

// void	store_stat(t_dir *dir)
// {
//             ft_putendlcolor("store_stat();", MAGENTA);
// 	int	i;
// 	t_s *tmp;

// 	i = -1;
// 	tmp = dir->s;
// 	dir->s->next = NULL;
// 	while (dir->names[++i])
// 	{
// 		get_stat(dir, dir->names[i], 0);
// 		tmp->name = ft_strdup(dir->names[i]);
// 		tmp->dev = dir->stat.st_dev;
// 		tmp->ino = dir->stat.st_ino;
// 		tmp->mode = dir->stat.st_mode;
// 		tmp->nlink = dir->stat.st_nlink;
// 		tmp->uid = dir->stat.st_uid;
// 		tmp->gid = dir->stat.st_gid;
// 		tmp->rdev = dir->stat.st_rdev;
// 		tmp->size = dir->stat.st_size;
// 		tmp->blksize = dir->stat.st_blksize;
// 		tmp->blocks = dir->stat.st_blocks;
// 		tmp->atime = dir->stat.st_atime;
// 		tmp->mtime = dir->stat.st_mtime;
// 		tmp->ctime = dir->stat.st_ctime;
// 		if (!(tmp->next = (t_s *)malloc(sizeof(t_s))))
// 			perror("Malloc failed");
// 		tmp = tmp->next;
// 		tmp->next = NULL;
// 	}
// }
