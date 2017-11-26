/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 16:23:00 by vmercadi          #+#    #+#             */
/*   Updated: 2017/11/23 22:18:47 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Return the file owner's name of the file
*/

char	*owner(t_dir *dir)
{
	dir->pwd = *getpwuid(dir->stat.st_uid);
	return (dir->pwd.pw_name);
}

/*
** Return the group owner's name of the file
*/

char	*gid(t_dir *dir)
{
	dir->gr = *getgrgid(dir->stat.st_gid);
	return (dir->gr.gr_name);
}

/*
** Return the formated time of the file
*/

char	*mtime(t_dir *dir)
{
            // ft_putendlcolor("mtime();", MAGENTA);
	time_t	ti;
	char	*str;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	ti = dir->stat.st_mtime;
	tmp = ctime(&ti);
	tmp2 = ft_strnew(0);
	tmp3 = ft_strnew(0);
	str = ft_strnew(0);
	ti = time(NULL) - ti;
	if (ti > 15778800 || ti < 0)
	{
		str = ft_strncpy(str, &(tmp[4]), 6);
		str = ft_strjoin_free(str, " ");
		tmp3 = ft_strncpy(tmp3, &(tmp[20]), 4);
		tmp2 = ft_strjoin(str, tmp3);
		tmp2 = ft_strjoin_free(tmp2, " ");
		ft_strdel(&tmp3);
		ft_strdel(&str);
	}
	else
		tmp2 = ft_strncpy(tmp2, &(tmp[4]), 12);
	return (tmp2);
}

/*
** return the type of the file (1st letter of permissions)
*/

char	type(t_dir *dir)
{
	if (S_ISDIR(dir->stat.st_mode))
		return('d');
	else if (S_ISLNK(dir->stat.st_mode))
		return('l');
    else if (dir->stat.st_mode & S_IFIFO)
		return('p');
    else if (dir->stat.st_mode & S_IFCHR)
		return('c');
    else if (dir->stat.st_mode & S_IFBLK)
		return('b');
	else
		return('-');
}

/*
** Return the formated permissions of the file
*/

char	*mode(t_dir *dir)
{
	char	*str;

	str = ft_strnew(10);
	str[0] = type(dir);
	str[1] = (dir->stat.st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (dir->stat.st_mode & S_IWUSR) ? 'w' : '-';
	if (dir->stat.st_mode & S_IXUSR)
		str[3] = (dir->stat.st_mode & S_ISUID) ? 's' : 'x';
	else
		str[3] = (dir->stat.st_mode & S_ISUID) ? 'S' : '-';
	str[4] = (dir->stat.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (dir->stat.st_mode & S_IWGRP) ? 'w' : '-';
	if (dir->stat.st_mode & S_IXGRP)
		str[6] = (dir->stat.st_mode & S_ISGID) ? 's' : 'x';
	else
		str[6] = (dir->stat.st_mode & S_ISGID) ? 'S' : '-';
	str[7] = (dir->stat.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (dir->stat.st_mode & S_IWOTH) ? 'w' : '-';
	if (dir->stat.st_mode & S_IXOTH)
		str[9] = (dir->stat.st_mode & S_ISVTX) ? 't' : 'x';
	else
		str[9] = (dir->stat.st_mode & S_ISVTX) ? 'T' : '-';
	return (str);
}

/*
** Display the total number of blocks in the directory
*/

void	print_blocks(t_dir *dir)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (dir->names[i])
	{
		get_stat(dir, dir->names[i], 0);
		nb += dir->stat.st_blocks;
		i++;
	}
	ft_putstr("total ");
	ft_putnbrendl(nb);
}

/*
** Return the complete name to display (work for for symbolic link too)
*/

char	*name(t_dir *dir, int i)
{
            //ft_putendlcolor("name();", MAGENTA);
	char	*str;
	char	*buf;
	int		size;

	size = PATH_MAX;
	buf = ft_strnew(size);
	str = ft_strdup(dir->names[i]);
	readlink(dir->file_path, buf, size);
	if (check_path(dir->file_path) == 3)
	{
		str = ft_strjoin_free(str, " -> ");
		str = ft_strjoin_free(str, buf);
	}
	return (str);
}

/*
** Return the size and if /dev return major/minor
*/

char	*size(t_dir *dir, int i, int *tab)
{
            //ft_putendlcolor("size();", MAGENTA);
	char		*str;
	int			ok;

	str = ft_strnew(0);
	ok = check_path(get_file_path(dir->path, dir->names[i]));
	if (ok == 4 || ok == 5)
	{
		str = ft_strjoin_free(str, repeat(tab[6] - int_space((int)major(dir->stat.st_rdev)), ' '));
		str = ft_strjoin_free(str, ft_itoa(major(dir->stat.st_rdev)));
		str = ft_strjoin_free(str, ",");
		str = ft_strjoin_free(str, repeat(tab[7] - int_space((int)minor(dir->stat.st_rdev)), ' '));
		str = ft_strjoin_free(str, ft_itoa(minor(dir->stat.st_rdev)));
	}
	else
	{
		str = ft_strjoin_free(str, repeat(tab[6] - int_space((int)major(dir->stat.st_rdev)), ' '));
		str = ft_strjoin_free(str, repeat(tab[7] - int_space((int)minor(dir->stat.st_rdev)), ' '));
		str = ft_strjoin_free(str, repeat(tab[4] - int_space((int)dir->stat.st_size) + 1, ' '));
		str = ft_strjoin_free(str, ft_itoa((int)dir->stat.st_size));
	}
	return ((str = ft_strjoin_free(str, " ")));
}

/*
** Print all the -l detail
*/

void	print_l(t_dir *dir)
{
            ft_putendlcolor("print_l();", MAGENTA);
	int	i;
	int	*tab;

	i = -1;
	tab = get_spaces(dir);
	while (dir->names[++i])
	{
		if (get_stat(dir, dir->names[i], 0))
		{
			ft_putstr(mode(dir));
			ft_putstr(repeat((tab[0] - ft_strlen(mode(dir))), ' '));
			ft_putstr(ft_itoa((int)dir->stat.st_nlink));
			ft_putstr(repeat(tab[1] - int_space((int)dir->stat.st_nlink), ' '));
			ft_putstr(owner(dir));
			ft_putstr(repeat(tab[2] - ft_strlen(owner(dir)), ' '));
			ft_putstr(gid(dir));
			ft_putstr(repeat(tab[3] - ft_strlen(gid(dir)), ' '));
			ft_putstr(size(dir, i, tab));
			ft_putstr(mtime(dir));
			ft_putstr(" ");
			l_color(dir, i);
			// ft_putendl(name(dir, i));
		}
	}
}

/*
** -l Option	Give more detailled informations
*/

void	opt_l(t_dir *dir)
{
            ft_putendlcolor("opt_l();", MAGENTA);
	int		i;
	char	*c;

	i = 0;
//	dir->file_path = get_file_path(dir->path, dir->names[i]);
	i = check_path(dir->path);
	if (i == 2 || i == 4)
		print_blocks(dir);
	else if (i == 0)
		return ;
	else
	{
		c = ft_strrchr(dir->path, '/');
		*c = '\0';
	}
	print_l(dir);
}
