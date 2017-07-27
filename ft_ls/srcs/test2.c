/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 14:56:42 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/27 15:01:15 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	swap_tab(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int	main ()
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 3);
	tab[0] = ft_strdup("Phrase A");
	tab[1] = ft_strdup("Phrase B");	
	tab[2] = NULL;
	ft_putendl("tab1 = ");
	ft_print_tab(tab);
	swap_tab(&tab[0], &tab[1]);
	ft_putendl("tab2 = ");
	ft_print_tab(tab);
	return (0);
}