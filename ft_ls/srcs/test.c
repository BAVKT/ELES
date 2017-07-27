/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:51:24 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/26 19:26:25 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


/*
** Test 
*/

void	print()
{
        ft_putendlcolor("print();", MAGENTA);		
	ft_putendl("Paths : ");
	ft_print_tab(g_b.paths);
	ft_putstr("Options : ");
	ft_putendl(g_b.options);
}