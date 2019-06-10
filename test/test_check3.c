/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 09:08:46 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/10 12:01:32 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/fillit.h"

/* FONCTION : main
 * PARAMETRE(S) : void
 * DESCRIPTION : 
 *     Main de test permettant de tester le comportement de ft_check3.c.
 */
int     main(void)
{
    t_tetri     tetri4 = {{{0, 0}, {0, 1}, {-1, 1}, {0, 2}}, 'D', NULL};
    t_tetri     tetri3 = {{{0, 0}, {0, 1}, {0, 2}, {-1, 2}}, 'C', &tetri4};
    t_tetri     tetri2 = {{{0, 0}, {0, 1}, {-1, 1}, {-1, 2}}, 'B', &tetri3};
    t_tetri     tetri1 = {{{0, 0}, {0, 1}, {-1, 1}, {-2, 1}}, 'A', &tetri2};
    t_tetri     *lst_tetri = &tetri1;
    t_tetri     *lst_explor;
    int         i = 1;

    lst_explor = lst_tetri;
    while (lst_tetri != NULL)
    {
        printf("Coord relatives tetri #%de tetri :\n", i);
        printf("1er bloc [%d][%d]\n", lst_explor->point[0].x, lst_explor->point[0].y);
        printf("2e bloc  [%d][%d]\n", lst_explor->point[1].x, lst_explor->point[1].y);
        printf("3e bloc  [%d][%d]\n", lst_explor->point[2].x, lst_explor->point[2].y);
        printf("4e bloc  [%d][%d]\n", lst_explor->point[3].x, lst_explor->point[3].y);
        lst_explor = lst_explor->next;
        i++;
    }
    ft_check3(lst_tetri);
    lst_explor = lst_tetri;
    while (lst_explor != NULL)
    {
        printf("Coord relatives explor #%de explor :\n", i);
        printf("1er bloc [%d][%d]\n", lst_explor->point[0].x, lst_explor->point[0].y);
        printf("2e bloc  [%d][%d]\n", lst_explor->point[1].x, lst_explor->point[1].y);
        printf("3e bloc  [%d][%d]\n", lst_explor->point[2].x, lst_explor->point[2].y);
        printf("4e bloc  [%d][%d]\n", lst_explor->point[3].x, lst_explor->point[3].y);
        lst_tetri = lst_tetri->next;
        i++;
    }
    return (0);
}