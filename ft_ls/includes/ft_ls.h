/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 00:56:37 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/28 18:19:55 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H
# define __FT_LS_H
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>

typedef struct		s_dir
{
	DIR				*rep;		//Le rep correspondant au path
	struct dirent	*dirent;	//Struct dirent du path
	struct stat		stat;		//La struct stat
	int				len;		//Nombre de fichiers/dossiers
	char 			*path;		//Le path actuel
	char			*file_path;	//Le path du file
	char			**names;	//Tab contenant les noms des fichiers dans l'ordre a afficher
	char			**display;	//Contient la ligne finale a afficher 
	char			**dir_tab;	//Tab contenant tous les dirs dans du repertoire courant
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
int					tab_len(char **tab);
char				**lexico_sort(char **tab);
char				*opt_tab(char **av);
void				opt_a(t_dir *dir);
void				opt_R(t_dir *dir);
void				opt_r(t_dir *dir);
void				opt_t(t_dir *dir);
void				opt_l();
int					check_path(char *path);
void				error_path(char *arg);
void				get_names(t_dir *dir);
void				usage();
void				display(t_dir *dir);
void				display_color(t_dir *dir);
char				*get_file_path(char *path, char *name);
void				print();
void				free_tab(char **tab);
void				basic_sort(t_dir *dir);

#endif