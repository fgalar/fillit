/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 07:53:26 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/11 11:48:04 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/fillit.h"

/* FONCTION : FIND_TRSL
 * PARAMETRE(S) : t_point *point |le tableau (x,y) des blocs du tetramino|
 *                int *trsl_x, *trsl_y |les translations en x et y à appliquer aux blocs|
 * DESCRIPTION : 
 *     Permet de déterminer les translations x et y aux blocs constituant le tetramino
 *     de manière à ne pas avoir de coordonnées relatives négatives.
 * RETOUR :
 *     rien.
 */
void    ft_find_trsl(t_tetri *piece, int *trsl_x, int *trsl_y)
{
    int     i;
    int     j;

    i = -1;
    j = -1;
    while (++i < 4)
    {
        if (piece->point[i].x < *trsl_x)
            *trsl_x = piece->point[i].x;
        if (piece->point[i].y < *trsl_y)
            *trsl_y = piece->point[i].y;
    }
}

/* FONCTION : APPLY_TRSL
 * PARAMETRE(S) : t_point *point |le tableau (x,y) des blocs du tetramino|
 *                int *trsl_x, *trsl_y |les translations en x et y à appliquer aux blocs|
 * DESCRIPTION : 
 *     Permet d'appliquer les translations x et y aux blocs constituant le tetramino
 *     de manière à ne pas avoir de coordonnées relatives négatives.
 * RETOUR :
 *     rien.
 */
void    ft_apply_trsl(t_tetri *piece, int *trsl_x, int *trsl_y)
{
    int     i;
    int     j;

    i = -1;
    j = -1;
    while (++i < 4)
    {
        piece->point[i].x = piece->point[i].x - *trsl_x;
        piece->point[i].y = piece->point[i].y - *trsl_y;
    }
}

/* FONCTION : CHECK_3
 * PARAMETRE(S) : t_tetri *tetri |le maillon d'un tetramino|
 * DESCRIPTION : 
 *     Permet de déterminer et d'appliquer les translations x et y aux blocs constituant
 *     le tetramino de manière à ne pas avoir de coordonnées relatives négatives.
 *     Les coordonnées relatives des blocs sont directements modifiées.
 * RETOUR :
 *     rien.
 */
void    ft_check3(t_tetri *tetri)
{
    int         trsl_x;
    int         trsl_y;
    t_tetri     *explor;

    explor = tetri;
    while (explor != NULL)
    {
        trsl_x = 0;
        trsl_y = 0;
        ft_find_trsl(explor, &trsl_x, &trsl_y);
        ft_apply_trsl(explor, &trsl_x, &trsl_y);
        explor = explor->next;
    }
}