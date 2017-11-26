/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:43:03 by vmercadi          #+#    #+#             */
/*   Updated: 2017/11/26 16:43:55 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Sort a tab by ASCII
*/

char	**sort_ascii(char **tab)
{
            ft_putendlcolor("sort_ascii();", MAGENTA);
	int	k;
	int	ok;

	k = 0;
	ok = 0;
	if (!tab)
		return (NULL);
	while (tab[k + 1])
	{
		if (ft_strcmp(tab[k], tab[k + 1]) > 0)
		{
			swaaap(&tab[k], &tab[k + 1]);
			k = 0;
		}
		k++;
		if (!tab[k + 1] && !ok)
		{
			k = 0;
			ok = 1;
		}
	}
	tab[k + 1] = NULL;
	return (tab);
}
