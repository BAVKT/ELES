/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 03:27:40 by vmercadi          #+#    #+#             */
/*   Updated: 2017/11/26 19:23:03 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Check the path, return 2 if path is dir 1,
** if path is file, 3 if symbolic link 0 else
*/

int     check_path(char *path)
{
               // ft_putendlcolor("check_path();", MAGENTA);
    struct stat st;
    int     r;

    r = 0;
    if (lstat(path, &st) == -1)
        r = 0;
    if (S_ISREG(st.st_mode))
        r = 1;
    else if (S_ISDIR(st.st_mode))
        r = 2;
    else if (S_ISLNK(st.st_mode))
        r = 3;
    else if (st.st_mode & S_IFBLK)
        r = 4;
    else if (st.st_mode & S_IFCHR)
        r = 5;
    else if (st.st_mode & S_IFIFO)
        r = 6;
    return (r);
}

/*
** return 1 if path is . or ..
*/

int     check_point(char *path)
{
            // ft_putendlcolor("check_point();", MAGENTA);
    if (ft_strcmp(path, ".") != 0 && ft_strcmp(path, "..") != 0)
        return (0);
    return (1);
}
