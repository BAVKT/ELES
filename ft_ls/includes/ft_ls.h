/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 00:56:37 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/13 19:30:47 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H
# define __FT_LS_H
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <errno.h>
# include <limits.h>
//# include <attr/xattr.h>

typedef struct		s_dir
{
	DIR				*rep;		//Le rep correspondant au path
	struct dirent	*dirent;	//Struct dirent du path
	struct stat		stat;		//La struct stat
	struct passwd	pwd;		//Struct password
	struct group	gr;			//Struct group
	int				len;		//Nombre de fichiers/dossiers
	char 			*path;		//Le path actuel
	char			*file_path;	//Le path du file
	char			**names;	//Tab contenant les noms des fichiers dans l'ordre a afficher
	char			**display;	//Contient la ligne finale a afficher 
	char			**dir_tab;	//Tab contenant tous les dirs du repertoire courant
}					t_dir;

typedef struct		s_base
{
	int				nbpaths;	//le nombre de paths donnés
	char			**paths;	//Les paths passés en arg
	char			*options;	//Les options passées
}					t_base;
t_base				g_b;

int					main();
void				ls(char *path);
void				init_base(char **av);
void				init_dir(t_dir *dir, char *path);
void				set_paths(char **av);
int					len_dirent(t_dir *dir);
char				**lexico_sort(char **tab);
char				*opt_tab(char **av);
void				opt_a(t_dir *dir);
void				opt_R(t_dir *dir);
void				opt_r(t_dir *dir);
void				opt_t(t_dir *dir);
void				opt_l(t_dir *dir);
void				opt_u(t_dir *dir);
int					check_path(char *path);
void				error_path(char *arg);
int					error(char *name, int e);
void				usage();
void				get_names(t_dir *dir);
void				display(t_dir *dir);
void				display_color(t_dir *dir);
char				*get_file_path(char *path, char *name);
void				basic_sort(t_dir *dir);
int					check_point(char *path);
char				*mode(t_dir *dir);
char				*owner(t_dir *dir);
char				*gid(t_dir *dir);
char				*mtime(t_dir *dir);
int					*get_spaces(t_dir *dir);
int					get_int_space(int nb);
void				clean_base();
void				clean_sdir(t_dir *dir);
void				print_blocks(t_dir *dir);
void				get_dir_tab(t_dir *dir);
int					display_file(t_dir *dir);
void				print_l(t_dir *dir);

#endif