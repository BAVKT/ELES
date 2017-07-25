/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 03:27:40 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/25 21:48:43 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Check the path, return 2 if path is dir 1, 
** if path is file, 3 if symbolic link 0 else 
*/

int     check_path(char *path)
{
            ft_putstrcolor("check_path();", MAGENTA);
    struct stat st;

    stat(path, &st);
    if (S_ISDIR(st.st_mode))
        return (2);
    else if (S_ISREG(st.st_mode))
        return (1);                                             
    else if (S_ISLNK(st.st_mode))
        return (3);
    error_path(path);
    return (0);
}


