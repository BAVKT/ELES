/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 03:27:40 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/07 06:14:58 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//Faire un recursif pour checker les fichiers 


/*
** Check if the given path exist
*/
int		check_path(char *path)
{
			ft_putendl("check_path();");
	struct stat fs;

	stat(path, &fs);
	if (!fs.st_size)
	{
		error_path(path);
		return (0);
	}
	return (1);
}
