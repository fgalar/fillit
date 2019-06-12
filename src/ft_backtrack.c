/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:02:38 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/12 18:06:19 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fillit.h"
#include "../libft/libft.h"

/* FONCTION : SQRT
 * PARAMETRE(S) : unsigned int nb |l'entier dont la racine est à déterminer|
 * DESCRIPTION : 
 *     Retourne la racine entière inférieure ou égale à l'entier passé en paramètre.
 * RETOUR :
 *     la racine carrée calculée.
 */
int     ft_sqrt(int nb)
{
    int racine;

    racine = 0;
    if (nb < 0)
        return (-1);
    while (racine * racine < nb)
        racine++;
    return (racine);
}

/* FONCTION : FILL_WITH_POINT
 * PARAMETRE(S) :   char **grid |La grille où le backtrak explorera le placement des tetraminos|
 * DESCRIPTION : 
 *      La fonction remplie la grille (grid) avec des '.'.
 * RETOUR :
 *     rien.
 */
void    fill_with_point(char ***grid)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (*grid[i])
    {
        while (*grid[i][j])
        {
            *grid[i][j] = '.';
            j++;
        }
        i++;
    }

}

/* FONCTION : GRID
 * PARAMETRE(S) :   char **grid |La grille ou le backtrak explorera le placement des tetramino|
 *                  int size |le côté de la grille|
 * DESCRIPTION : 
 *      La fonction alloue et remplie la grille (grid) avec des '.'.
 *      Grid permet au backtrack d'explorer le placement des pieces et sera retourner à la fin 
 *      de celui-ci afin d'être afficher dans par ft_prt_solution dans le main. 
 * RETOUR :
 *     char **grid
 */
char    **ft_grid(int size)
{
    char    **grid;
    int     i;

    i = 0;
    if (!(grid = (char**)ft_memalloc(size + 1)))
        return (NULL);
    while (i < size)
    {
        if (!(grid[i] = (char*)ft_memalloc(size + 1)))
        {
            i++;
            while (--i >= 0)
                free(grid[i]);
            free(grid);
            return (NULL);
        }
        grid[i][size] = '\0';
        i++;
    }
    grid[size] = "\0";
    fill_with_point(&grid);
    return (grid);
}

/* FONCTION : FREE_GRID
 * PARAMETRE(S) :   char ***grid |L'adresse de la grille à libérer|
 * DESCRIPTION : 
 *      Permet de libérer la grille passée en argument. 
 * RETOUR :
 *     rien
 */
void    ft_free_grid(char ***grid)
{
    int     i;

    i = 0;
    if (grid)
    {
        while (*grid[i])
        {
            free(*grid[i]);
            i++;
        }
        free(*grid);
        *grid = NULL;
    }
}

/* FONCTION : OFFSET_TETRA
 * PARAMETRE(S) :   t_tetri *lst_tetri ||
 *                  char **grid ||
 * DESCRIPTION : 
 *     >
 * RETOUR :
 *     -1|| 0 si le placement de la pièce est impossible || possible.
 */
int     ft_offset_tetra(t_tetri *tetri, char **grid, int *dx, int *dy)
{
    int     size;
    int     bloc;

    size = ft_strlen(grid[0]);
    bloc = 0;
    while (bloc <= 3)
    {
        if (grid[tetri->point[bloc].x + *dx][tetri->point[bloc].y + *dy] == '.')
            bloc++;
        else
        {
            *dx = *dx + 1;
            if (*dx >= size)
            {
                *dx = 0;
                *dy = *dy + 1;
            }
            if (*dy >= size)
                break ;
            bloc = 0;
        }
    }
    return ((*dy >= size) ? -1 : 0);
}

/* FONCTION : PLACE_1TETRA
 * PARAMETRE(S) :   t_tetri *lst_tetri ||
 *                  char **grid ||
 * DESCRIPTION : 
 *     >
 * RETOUR :
 *     >
 */
void    ft_place_1tetra(t_tetri *tetri, char ***grid, int dx, int dy)
{
    int     bloc;

    bloc = 0;
    while (bloc <= 3)
    {
        *grid[tetri->point[bloc].x + dx][tetri->point[bloc].y + dy] = tetri->c;
        bloc++;
    }
}

/* FONCTION : PUT_ALL_TETRA
 * PARAMETRE(S) :   t_tetri *lst_tetri ||
 *                  char **grid ||
 * DESCRIPTION : 
 *     >
 * RETOUR :
 *     >
 */
int     ft_put_all_tetra(t_tetri *lst_tetri, char ***grid, int size)
{
    int     dx;
    int     dy;

    if (lst_tetri != NULL)
    {
        dx = 0;
        dy = 0;
        if (ft_offset_tetra(lst_tetri, *grid, &dx, &dy) == -1)
            return (0);
        ft_place_1tetra(lst_tetri, grid, dx, dy);
        ft_put_all_tetra(lst_tetri->next, grid, size);
    }
    return (1);
}

/* FONCTION : BACKTRACK
 * PARAMETRE(S) : 
 * DESCRIPTION : 
 *     >
 * RETOUR :
 *     >
 */
char    **ft_backtrack(t_tetri *lst_tetri, int nb_tetri)
{
    char    **grid;
    int     size;
    int     extra_size;
    int     stop;

    stop = 0;
    ft_check3(lst_tetri);
    extra_size = 0;
    while (stop == 0)
    {
        size = ft_sqrt(nb_tetri * 4) + extra_size;
        grid = ft_grid(size);
        if ((stop = ft_put_all_tetra(lst_tetri, &grid, size)) == 0)
        {
            ft_free_grid(&grid);
            extra_size++;
        }
    }
    return (grid);
}