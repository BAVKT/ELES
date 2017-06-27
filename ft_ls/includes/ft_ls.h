/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 00:56:37 by vmercadi          #+#    #+#             */
/*   Updated: 2017/06/27 03:02:49 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H
# define __FT_LS_H
# include "libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <time.h>

typedef struct		s_base
{
	DIR				*rep;
	struct dirent	*dirent;
	int				len;		//nombre de fichiers/dossiers
}					t_base;
t_base				g_b;

int		main();
void	ft_ls();
char	**lexico_sort(char **tab);
int		len_dirent();
void	init_base();

#endif