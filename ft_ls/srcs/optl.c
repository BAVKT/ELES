/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 16:23:00 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/04 16:29:38 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Everything that is linked to -l display option.
** trouver comment afficher tous les differents modes
** Potentiellement une fonction par mode... 
*/

/*
If -l for each file : 
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
** -l Option	Give more detailled informations 
*/

void	opt_l(t_dir *dir)
{
            ft_putendlcolor("opt_l();", MAGENTA);
	int i;

	i = 0;
	while (dir->names[i])
	{
		dir->file_path = get_file_path(dir->path, dir->names[i]);
		stat(dir->file_path, &dir->stat);
		ft_putendl("  ");
		ft_putstr(dir->stat.st_mode);
		ft_putendl("  ");
		ft_putstr(dir->stat.st_nlink);
		ft_putendl("  ");
		ft_putstr(dir->stat.st_uid);
		ft_putendl("  ");
		ft_putstr(dir->stat.st_gid);
		ft_putendl("  ");
		ft_putstr(dir->stat.st_size);
		ft_putendl("  ");
		ft_putstr(dir->stat.st_mtime);
		ft_putendl(dir->names[i]);
		i++;
	}
}
