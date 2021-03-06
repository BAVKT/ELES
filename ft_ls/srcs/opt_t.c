/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 18:55:34 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/01 20:49:07 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void	swap_t(t_s *a, t_s *b)
{
	t_s c;

	c = *a;
	*a = *b;
	*b = c;
}

void	remptab(t_dir *dir, t_s *s)
{
		ft_putendlcolor("remp_tab();", MAGENTA);
	int		i;
	int		len;

	len = tab_len(dir->names);
	free_tab((void **)dir->names);
	if (!(dir->names = (char **)malloc(sizeof(char *) * (len + 1))))
		perror("MALLOC FAILED");
	i = -1;
	while (++i < len)
		dir->names[i] = ft_strdup(s[i].name);
	dir->names[i] = NULL;
	ft_putnbrendl(len);
	opt_r(dir);
 }

/*
** -t Option	Sort by time
*/

void	opt_t(t_dir *dir)
{
            ft_putendlcolor("opt_t();", MAGENTA);
	int	i;
	int	time;

	i = 0;
	while (dir->names[i] && dir->names[i + 1])
	{
		dir->file_path = get_file_path(dir->path, dir->names[i]);
		stat(dir->file_path, &dir->stat);
		time = dir->stat.st_mtime;
		dir->file_path = get_file_path(dir->path, dir->names[i + 1]);
		stat(dir->file_path, &dir->stat);
		if (dir->stat.st_mtime > time)
		{
			swaaap(&dir->names[i], &dir->names[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

// void	opt_t(t_dir *dir)
// {
// 		ft_putendlcolor("opt_t();", MAGENTA);
// 	int		i;
// 	int		size;
// 	time_t	ti;
// 	t_s		*s;

// 	size = tab_len(dir->names);
// 	s = store_stat(dir, size);
// 	i = -1;
// 	while (++i < size - 1)
// 	{
// 		ti = s[i].mtime;
// 		if (ti > s[i + 1].mtime)
// 		{
// 			swap_t(&s[i], &s[i + 1]);
// 			i = -1;
// 		}
// 	}
// 	remptab(dir, s);
// }

t_s		*store_stat(t_dir *dir, int size)
{
		ft_putendlcolor("store_stat();", MAGENTA);
	int	i;
	t_s *s;

	if (!(s = (t_s *)malloc(sizeof(t_s) * tab_len(dir->names) + 1)))
		perror("MALLOC FAILED");
	i = -1;
	while (++i < size)
	{
		get_stat(dir, dir->names[i], 0);
		s[i].name = ft_strdup(dir->names[i]);
		s[i].ino = dir->stat.st_ino;
		s[i].mode = dir->stat.st_mode;
		s[i].nlink = dir->stat.st_nlink;
		s[i].uid = dir->stat.st_uid;
		s[i].gid = dir->stat.st_gid;
		s[i].rdev = dir->stat.st_rdev;
		s[i].size = dir->stat.st_size;
		s[i].blksize = dir->stat.st_blksize;
		s[i].blocks = dir->stat.st_blocks;
		s[i].atime = dir->stat.st_atime;
		s[i].mtime = dir->stat.st_mtime;
		s[i].ctime = dir->stat.st_ctime;
	}
	return (s);
}

//#####################################################################

// void	opt_t(t_dir *dir)
// {
// 			ft_putendlcolor("opt_t();", MAGENTA);
// 	int		i;
// 	time_t	ti;
// 	t_s		*tmp;

// 	i = 0;
// 	dir->s = (t_s *)malloc(sizeof(t_s));
// 	dir->s->next = NULL;
// 	tmp = dir->s;
// 	while (dir->names[i])
// 		store_stat(dir, tmp, dir->names[i++]);
// 	i = 0;
// 			ft_putendl("TAB1 = ");
// 			ft_print_tab(dir->names);
// 			ft_putendl("======================");
// 	while (dir->names[i + 1])
// 	{
// 		tmp = dir->s;
// 		while (tmp->next && ft_strcmp(tmp->name, dir->names[i]))
// 			tmp = tmp->next;
// 		ti = tmp->mtime;
// 		tmp = dir->s;
// 		while (tmp->next && ft_strcmp(tmp->name, dir->names[i + 1]))
// 			tmp = tmp->next;
// 		if (tmp->mtime > ti)
// 		{
// 			ft_putendl("BLI");
// 			ft_putendl(dir->names[i]);
// 			ft_putendl(dir->names[i + 1]);
// 			ft_putendl("======================");
// 			swaaap(&dir->names[i], &dir->names[i + 1]);
// 			i = -1;
// 		}
// 		i++;
// 	}
// 			ft_putendl("TAB2 = ");
// 			ft_print_tab(dir->names);
// 			ft_putendl("======================");
// }

// void	store_stat(t_dir *dir, t_s *tmp, char *name)
// {
// 		ft_putendlcolor("store_stat();", MAGENTA);
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


//#####################################################################

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
