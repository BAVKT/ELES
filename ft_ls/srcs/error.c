/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 05:31:42 by vmercadi          #+#    #+#             */
/*   Updated: 2017/11/26 20:22:36 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** When you can't open a dir
*/

int		error(char *name, int e)
{
			ft_putendlcolor("error();", MAGENTA);
	ft_putstr("./ft_ls: ");
	ft_putstr(name);
	ft_putstr(": ");
	if (e == 1)
		ft_putendl("Bad file descriptor");
	else if (e == 2)
		ft_putendl("Permission denied");
	else if (e == 3)
		ft_putendl("directory causes a cycle");
	return(0);
}

/*
** Error if path does not exist
*/

void	error_path(char *arg)
{
			ft_putendlcolor("error_path();", MAGENTA);
	ft_putstr("./ft_ls: ");
	ft_putstr(arg);
	ft_putendl(": No such file or directory");
}

/*
** Print usage
*/

void	usage()
{
	ft_putendl("usage: ./ft_ls [-laRrt] [file ...]");
	exit(1);
}
