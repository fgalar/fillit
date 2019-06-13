/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_debug.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:43:36 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/13 16:08:45 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"
#include "../libft/libft.h"

void    ft_print_all_tetra(t_tetri *lst_tetri)
{
    t_tetri     *temp;
    int         nb_blocs;
    int         nb_tetramino;

    temp = lst_tetri;
    nb_tetramino = 1;
    while (temp != NULL)
    {
        nb_blocs = 0;
        printf("==========\n");
        printf("  TETRAMINO #%d\n", nb_tetramino);
        printf(" letter=%c\n", temp->c);
        while (nb_blocs < 4)
        {
            printf("bloc #%d : [%d][%d]\n", nb_blocs+1, temp->point[nb_blocs].x, temp->point[nb_blocs].y);
            nb_blocs++;
        }
        nb_tetramino++;
        printf("==========\n");
        temp = temp->next;
    }
}

void    ft_print_grid(char **grid)
{
    int     i;

    i = 0;
    if (grid)
    {
        while (grid[i])
        {
            ft_putendl(grid[i]);
            i++;
        }
    }
}