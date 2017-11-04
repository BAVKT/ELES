/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 00:55:02 by vmercadi          #+#    #+#             */
/*   Updated: 2017/11/04 20:04:49 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Start LS and the options
*/

void	ls(char *path)
{
            ft_putendlcolor("ls();", MAGENTA);
    t_dir	dir;
    int		i;
    
    init_dir(&dir, path);
    if (display_file(&dir))
        return ;
    if (dir.len)
    {
        (ft_strchr(g_b.options, 'a')) ? opt_a(&dir) : get_names(&dir);
        basic_sort(&dir);
        !ft_strchr(g_b.options, 't') ? i = 0 : opt_t(&dir);
        !ft_strchr(g_b.options, 'u') ? i = 0 : opt_u(&dir);
        !ft_strchr(g_b.options, 'r') ? i = 0 : opt_r(&dir);
        if (ft_strchr(g_b.options, 'l'))
        	opt_l(&dir);
        else
        {	
        	ft_cp_tab(dir.display, dir.names);
        	display_color(&dir);
        }
    }
    !ft_strchr(g_b.options, 'R') ? i = 0 : opt_R(&dir);
    //  clean_sdir(&dir);
}

int		main(int ac, char **av)
{
            ft_putendlcolor("main();", MAGENTA);
	int	i;
	int	j;

	i = 0;
    g_b.ac = ac;
    init_base(av);
	j = tab_len(g_b.paths);
	while (i < j && g_b.paths[i])
    {
        ft_putendl("XBLI");
        ft_putnbrendl(i);   
        if (g_b.paths[i])
        {
            ft_putendl("111111");
            ft_putendl(g_b.paths[i]);
        }
        else 
            ft_putendl("222222");
        ft_putendl("yolo");
        ft_putnbrendl(ft_strlen(g_b.paths[i]));
		ls(g_b.paths[i]);
        i++;
    }
 //   clean_base();
	return (0);
}
