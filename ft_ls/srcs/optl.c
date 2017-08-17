/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 16:23:00 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/13 19:38:12 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
	
/*
-l for each file : 
- mode 							st_mode
- number of links				st_nlink
- owner (though not for -g)		st_uid
- group, 						st_gid
- size in bytes,				st_size
- last mod(“mmm dd HH:MM”)		st_mtime
- pathname. 					name
In addition, for each directory whose contents are displayed, the first line 
displayed is the total number of blocks used by the files in the directory. 
Blocks are 512 bytes unless overridden by the -k option or 
BLOCKSIZE environment variable.
If the owner or group name is not a known user or group name, respectively, 
the numeric ID is displayed.
If the file is a character special or block special file, 
the major and minor device numbers for the file are displayed in the size field.
If file is a symbolic link, the pathname of the linked-to file is preceded by “->”.
The file mode printed under the -l options consists of the entry type, 
owner permissions, group permissions, and other permissions. 
*/
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
	time_t	now;
	time_t	ti;
	char	*str;
	char	*tmp;
	char	*tmp2;

	now = time(NULL);
	ti = dir->stat.st_mtime;
	tmp = ctime(&ti);
	tmp2 = ft_strnew(0);
	str = ft_strnew(0);
	ti = now - ti;
	if (ti > 15778800 || ti < 0)
		tmp2 = ft_strncpy(tmp2, &(tmp[4]), 15);
	else
		tmp2 = ft_strncpy(tmp2, &(tmp[4]), 12);
	return (str = ft_strjoin_free(str, tmp2));
}

/*
** Return the formated permissions of the file
*/

char	*mode(t_dir *dir)
{
	char	*str;

	str = ft_strnew(10);
	if (S_ISDIR(dir->stat.st_mode))
		str[0] = 'd';
	else if (S_ISLNK(dir->stat.st_mode))
		str[0] = 'l';
	else
		str[0] = '-';
	str[1] = (dir->stat.st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (dir->stat.st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = (dir->stat.st_mode & S_IXUSR) ? 'x' : '-';
	str[4] = (dir->stat.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (dir->stat.st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = (dir->stat.st_mode & S_IXGRP) ? 'x' : '-';
	str[7] = (dir->stat.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (dir->stat.st_mode & S_IWOTH) ? 'w' : '-';
	str[9] = (dir->stat.st_mode & S_IXOTH) ? 'x' : '-';
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
		dir->file_path = get_file_path(dir->path, dir->names[i]);
		lstat(dir->file_path, &dir->stat);
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
** Print all the -l detail
*/

void	print_l(t_dir *dir)
{
	int	i;
	int	*tab;

	i = 0;
	tab = get_spaces(dir);
	while (dir->names[i])
	{
		dir->file_path = get_file_path(dir->path, dir->names[i]);
		lstat(dir->file_path, &dir->stat);
		ft_putstr(mode(dir));
		ft_putstr(repeat((tab[0] - ft_strlen(mode(dir))), ' '));
		ft_putstr(ft_itoa((int)dir->stat.st_nlink));
		ft_putstr(repeat(tab[1] - get_int_space((int)dir->stat.st_nlink), ' '));
		ft_putstr(owner(dir));
		ft_putstr(repeat(tab[2] - ft_strlen(owner(dir)), ' '));
		ft_putstr(gid(dir));
		ft_putstr(repeat(tab[3] - ft_strlen(gid(dir)), ' '));
		ft_putstr(ft_itoa(dir->stat.st_size));
		ft_putstr(repeat(tab[4] - get_int_space((int)dir->stat.st_size), ' '));
		ft_putstr(mtime(dir));
		ft_putstr(" ");
		ft_putendl(name(dir, i));
		i++;
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
	dir->file_path = get_file_path(dir->path, dir->names[i]);
	if (check_path(dir->path) == 2) 
		print_blocks(dir);
	else
	{
		c = ft_strrchr(dir->path, '/');
		*c = '\0';
	}
	print_l(dir);
}
