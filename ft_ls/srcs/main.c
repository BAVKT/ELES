  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 00:55:02 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/08 05:39:52 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Lance le LS, appelle les options necessaire et est le recursif
*/

void	ls(char *path)
{
            ft_putendlcolor("ls();", MAGENTA);
	t_dir	dir;
	int		i;


	init_dir(&dir, path);
    ft_strchr(g_b.options, 'a') ? opt_a(&dir) : get_names(&dir);
    basic_sort(&dir);
    !ft_strchr(g_b.options, 't') ? : opt_t(&dir);
    !ft_strchr(g_b.options, 'r') ? : opt_r(&dir);
    !ft_strchr(g_b.options, 'l') ? : opt_l(&dir);
    ft_cp_tab(dir.display, dir.names);
    display_color(&dir);
    if (ft_strchr(g_b.options, 'R'))
    {
    	i = 0;

        path = ft_strjoin(path, "/");
        while (dir.dir_tab[i])
        {
    		ls(ft_strjoin(path, dir.dir_tab[i++]));
        }
    }
}

int		main(int ac, char **av)
{
            ft_putendlcolor("main();", MAGENTA);
	int	i;
	int	j;

	i = 0;
	(void)ac;
	init_base(av);
	j = tab_len(g_b.paths);
	while (i < j)
		ls(g_b.paths[i++]);
	print();
	return (0);
}
