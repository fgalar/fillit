/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 19:11:15 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/06 22:53:11 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/fillit.h"

int     main(int ac, char **av)
{
    int         fd;
    int         nb_tetrimino;
    char        **solution;
    t_tetri     *lst_tetri;

    nb_tetrimino = 0;
    fd = open(av[1], O_RDONLY);
    
    if (ac != 2)
    
        putendl("usage :");
        return (-1);
    }
    if (fd == -1)
    {
        putendl("error");
        return (-1);
    }
    nb_tetrimino = ft_check(&fd);
    close(fd);
    //fd = open(av[1], O_RDONLY);
    if (nb_tetrimino != 1)
    {
        //t_tetri = ft_parsing(fd);
        lst_tetri = ft_parsing(av[1]);
    }
    ft_backtrack(solution, lst_tetri, nb_tetrimino);
    ft_prt_solution(solution);
    return (0);
}