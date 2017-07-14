/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 05:31:42 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/08 05:39:55 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Error if path does not exist
*/

void	error_path(char *arg)
{
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
