  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 00:55:02 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/08 05:39:52 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
If -l for each file : 
- mode 
- number of links
- owner (though not for -g)
- group, size in bytes 
- time of last modification (“mmm dd HH:MM”)
- pathname. 
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
** Lance le LS, appelle les options necessaire et est le recursif
*/

void	ls(char *path)
{
            ft_putendlcolor("ls();", MAGENTA);
	t_dir	dir;
	int		i;

	init_dir(&dir, path);
    ft_strchr(g_b.options, 'a') ? opt_a(&dir) : get_names(&dir);
    basic_sort(&dir);
    !ft_strchr(g_b.options, 't') ? i = 0 : opt_t(&dir);
    !ft_strchr(g_b.options, 'r') ? i = 0 : opt_r(&dir);
    !ft_strchr(g_b.options, 'l') ? i = 0 : opt_l(&dir);
    ft_cp_tab(dir.display, dir.names);
    display_color(&dir);
    !ft_strchr(g_b.options, 'R') ? i = 0 : opt_R(&dir);
}

int		main(int ac, char **av)
{
            ft_putendlcolor("main();", MAGENTA);
	int	i;
	int	j;

	i = 0;
	(void)ac;
	init_base(av);
	j = tab_len(g_b.paths);
	while (i < j)
		ls(g_b.paths[i++]);
	print();
	return (0);
}
