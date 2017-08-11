/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 16:23:00 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/11 16:44:51 by vmercadi         ###   ########.fr       */
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


//struct stat {
//  dev_t     st_dev;      /* ID du périphérique contenant le fichier */
//  ino_t     st_ino;      /* Numéro inœud */
//  mode_t    st_mode;     /* Protection */
//  nlink_t   st_nlink;    /* Nb liens matériels */
//  uid_t     st_uid;      /* UID propriétaire */
//  gid_t     st_gid;      /* GID propriétaire */
//  dev_t     st_rdev;     /* ID périphérique (si fichier spécial) */
//  off_t     st_size;     /* Taille totale en octets */
//  blksize_t st_blksize;  /* Taille de bloc pour E/S */
//  blkcnt_t  st_blocks;   /* Nombre de blocs alloués */
//  time_t    st_atime;    /* Heure dernier accès */
//  time_t    st_mtime;    /* Heure dernière modification */
//  time_t    st_ctime;    /* Heure dernier changement état */
//};


/*
** Return the formated permissions of the file
*/

char	*get_mode(t_dir *dir)
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
** Return the file owner's name of the file
*/

char	*get_owner(t_dir *dir)
{
	dir->pwd = *getpwuid(dir->stat.st_uid);
	return (dir->pwd.pw_name);
}

/*
** Return the group owner's name of the file
*/

char	*get_gid(t_dir *dir)
{
	dir->gr = *getgrgid(dir->stat.st_gid);
	return (dir->gr.gr_name);
}

/*
** Return the formated time of the file
*/
/*
char	*get_time(t_dir *dir)
{
	time_t	now;
	time_t	ti;
	time_t	final;
	char	*str;

	now = time(NULL);
	ti = dir->stat.st_mtime;
	str = ctime(&ti);
	final = now - ti;
	ft_putchar(' ');
	ft_putnstr(&(str[4]), 6);
	ft_putchar(' ');
	if (final < (-3600 * 24 * 30.5 * 6) || final > (3600 * 24 * 30.5 * 6))
	{
		ft_putchar(' ');
		ft_putnstr(&(str[20]), 4);
	}
	else
	{
		ft_putnstr(&(str[11]), 5);
		ft_putchar(' ');
	}
	return (str);
}
*/
/*
char	*get_time(t_dir *dir)
{
	time_t	now;

}
*/
char	*get_time(t_dir *dir)
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
		tmp2 = ft_strncpy(tmp2, &(tmp[4]), 17);
	else
		tmp2 = ft_strncpy(tmp2, &(tmp[4]), 12);
	return (str = ft_strjoin_free(str, tmp2));
}

/*
** -l Option	Give more detailled informations 
*/

void	opt_l(t_dir *dir)
{
            ft_putendlcolor("opt_l();", MAGENTA);
	int		i;
	
	i = 0;
	while (dir->names[i])
	{
		dir->file_path = get_file_path(dir->path, dir->names[i]);
		stat(dir->file_path, &dir->stat);
		ft_putstr(get_mode(dir));
		ft_putstr("  ");
		ft_putstr(ft_itoa((int)dir->stat.st_nlink));
		ft_putstr("  ");
		ft_putstr(get_owner(dir));
		ft_putstr("  ");
		ft_putstr(get_gid(dir));
		ft_putstr("  ");
		ft_putstr(ft_itoa(dir->stat.st_size));
		ft_putstr("  ");
		ft_putstr(get_time(dir));
		ft_putstr("  ");
		ft_putendl(dir->names[i]);
		i++;
	}
}
