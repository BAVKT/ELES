/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 00:56:37 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/07 06:05:30 by vmercadi         ###   ########.fr       */
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
	int				len;		//Nombre de fichiers/dossiers
	char 			*path;		//Le path actuel au cas ou c'tai pas clair
	char			**tabdir;	//Tab contenant les noms des fichiers
	struct s_dir	*next;
}					t_dir;
t_dir				g_d;

typedef struct		s_base
{
	struct s_dir	*sdir;		//Premier maillon struct s_dir
	int				nbpaths;	//le nombre de paths donnés
	char			**paths;	//Les paths passés en arg
	char			*options;	//Les options passées
}					t_base;
t_base				g_b;

int		main();
void	init_base();
void	init_dir();
void	set_paths(char **av);
int		len_dirent();
int		len_tab(char **tab);
void	ls();
char	**lexico_sort(char **tab);
char	*opt_tab(char **av);
void	print();
void	usage();
void	opt_a();
void	opt_R();
int		check_path(char *path);
void	error_path(char *arg);


#endif