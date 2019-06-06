/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:02:38 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/06 22:53:11 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../libft/libft.h"

/* FONCTION : SQRT
 * PARAMETRE(S) : 
 * DESCRIPTION : 
 *     >
 * RETOUR :
 *     >
 */
int     ft_sqrt(unsigned int nb)
{
    int racine;

    racine = 0;
    if (nb < 0)
        return (-1);
    while (racine * racine < nb)
        racine++;
    return (racine);
}

/* FONCTION : GRID
 * PARAMETRE(S) : 
 * DESCRIPTION : 
 *     >
 * RETOUR :
 *     >
 */
ft_grid(int size)
{
    char    **grid;
    int     i;

    i = 0;
    if (!(grid = (char**)ft_memalloc(14)))
        return (-1);
    while (i < size)
    {
        if (!(grid[i] = (char*)ft_memalloc(14)))
        {

        }
    }
    

}

/* FONCTION : BACKTRACK
 * PARAMETRE(S) : 
 * DESCRIPTION : 
 *     >
 * RETOUR :
 *     >
 */
void    ft_bactrack(char **solution, t_tetri *lst_tetri, int nb_tetri)
{

}