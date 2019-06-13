/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 19:11:15 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/13 18:41:29 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/fillit.h"
#include "libft/libft.h"


int     main(int ac, char **av)
{
    int         fd;
    int         nb_tetri;
    char        **solution;
    t_tetri     *lst_tetri = NULL;

    nb_tetri = 0;
    fd = open(av[1], O_RDONLY);
    
    if (ac != 2)
    {
        ft_putendl("usage :");
        return (-1);
    }
    if (fd == -1)
    {
        ft_putendl("error");
        return (-1);
    }
    nb_tetri = ft_check(&fd);
    printf("valeur de nb_tetri=%d\n", nb_tetri);
    close(fd);
    //fd = open(av[1], O_RDONLY);
    if (nb_tetri > 0)
    {
        //t_tetri = ft_parsing(fd);
        lst_tetri = ft_parsing(av);
    }
    printf("ici 5\n");
    solution = ft_backtrack(lst_tetri, nb_tetri);
    ft_prt_solution(solution);
    return (0);
}