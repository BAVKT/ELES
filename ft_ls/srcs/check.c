/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 03:27:40 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/08 05:39:54 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//VERSION QUI MARCHE A MOITIE
/*
** Check if the given path exist
*/
/*
int		check_path(char *path)
{
			ft_putendl("check_path();");
    int		i;
    char	*tmp;

    		ft_putendl(path);
    		ft_putendl(g_d.path);
    i = 0;
    tmp = ft_strnew(0);
    if (ft_strstr("/", path))
    {

    	while (path[i])
    		i++;
    	while (path[i] != '/')
    		i--;
    	tmp = ft_strncpy(path, path, path - &path[i]);
    }	
	else
    {
    	tmp = path;
    	path = ft_strdup(".");
    			ft_putendl(tmp);
    }
    i = 0;
    if ((g_d.rep = opendir(path)))
    {
        while ((g_d.dirent = readdir(g_d.rep)))
        {
            if (!ft_strcmp(tmp, g_d.dirent->d_name))
            {
            		ft_putendl(g_d.dirent->d_name);
                i = 1;
            }
        }
        closedir(g_d.rep);
    }
    		ft_putendl("AHUFUAEFHUAHFIAJJFOAFW");
    		ft_putnbrendl(i);
	g_d.path = ft_strdup(path);			
	if (!i)
		error_path(path);
    return (i);
}
*/

/*
** Return 1 if path is a dir, 0 if nop
*/

int     check_dir(char *path)
{
            ft_putendl("check_dir");
    if((g_d.rep = opendir(path)))
    {
        closedir(g_d.rep);
        return (1);
    }
    return(0);
}

/*
** If path is a file return 1, else 0
*/

int     check_file(char *path)
{
            ft_putendl("check_file");
    char    *tmp;
    char    *tmp2;
    char    *c;

    tmp = ft_strnew(0);
    tmp2 = ft_strnew(0);
    if ((c = ft_strrchr(path, '/')))
    {
        tmp = ft_strdup(c + 1);
        tmp2 = ft_strncpy(tmp2, path, c - path);
    }
    else
    {
        tmp = ft_strdup(path);
        tmp2 = ft_strdup(".");
    }
        ft_putendl("ya");
    g_d.rep = opendir(tmp2);
    while ((g_d.dirent = readdir(g_d.rep)))
    {
        if (!ft_strcmp(tmp, g_d.dirent->d_name))
        {
            closedir(g_d.rep);
            return (1);
        }
    }
    closedir(g_d.rep);
    return (0);
}

/*
** Check the path, return 2 if path is dir 1, if path is file, 0 else 
*/

int     check_path(char *path)
{
            ft_putendl("check_path();");
    char    *tmp;
    char    *c;

    tmp = ft_strnew(0);
    if ((c = ft_strrchr(path, '/')))
    {
        if (!*(c + 1))
        {
            while (*c != '/')
                c--;
        }
        tmp = ft_strncpy(tmp, path, c - path);
    }   
    else
        tmp = path;
    if (check_dir(path))
        return (2);
    else if (check_file(tmp))
        return (1);
    else
        error_path(path);    
    return (0);
}


// /*
// ** Split the path
// */
// char	*split_path()
// {
// 			ft_putendl("check_path();");
//     int		i;
//     char	*tmp;

//     		ft_putendl(g_d.path);
//     i = 0;
//     tmp = ft_strnew(1);
//     if (ft_strstr("/", g_d.path))
//     {
//     	while (g_d.path[i])
//     		i++;
//     	while (g_d.path[i] != '/')
//     		i--;
//     	tmp = ft_strncpy(g_d.path, g_d.path, g_d.path - &g_d.path[i]);
//     }	
// 	else
//     {
//     	tmp = g_d.path;
//     	g_d.path = ft_strdup(".");
//     			ft_putendl(tmp);
//     }
//     return (tmp);
// }

// /*
// ** Check if the given path exist
// */
// int		check_path(char *path)
// {
// 	int		i;
// 	char	*tmp;

//     i = 0;
//     g_d.path = ft_strdup(path);
//     tmp = ft_strnew(1);
// 	tmp = split_path();
//     if ((g_d.rep = opendir(g_d.path)))
//     {
//         while ((g_d.dirent = readdir(g_d.rep)))
//         {
//             if (!ft_strcmp(tmp, g_d.dirent->d_name))
//             {
//             		ft_putendl(g_d.dirent->d_name);
//                 i = 1;
//             }
//         }
//         closedir(g_d.rep);
//     }
//     		ft_putendl("AHUFUAEFHUAHFIAJJFOAFW");
//     		ft_putnbrendl(i);	
// 	if (!i)
// 		error_path(g_d.path);
//     return (i);
// }


