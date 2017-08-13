/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 15:30:43 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/13 16:10:58 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Free a tab
*/

void	free_tab(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_strdel((char**)&tab[i++]);
	ft_memdel((void**)tab);
}
