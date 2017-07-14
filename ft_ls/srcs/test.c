/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:51:24 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/08 05:39:54 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** tab_len
*/

int		len_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

/*
** Test 
*/

void	print()
{
	ft_putendl("Paths : ");
	ft_print_tab(g_b.paths);
	ft_putstr("Options : ");
	ft_putendl(g_b.options);
}