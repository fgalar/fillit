/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetramino.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:04:09 by mdavid            #+#    #+#             */
/*   Updated: 2019/05/23 11:06:25 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

/* FONCTION : CHECK_TETRAMINO
 * PARAMETRE(S) : buffer depuis la fonction CHECK. 
 * DESCRIPTION : 
 *     Permet de vérifier que le possible tetramino réccupéré
 *     est valide.
 * RETOUR :
 *     1 -> Le tetramino est invalide.
 *     0 -> Le tetramino est valide.
 */
int    ft_check_tetramino(char **buffer)
{
    int     **table_voisin;
    int     sum_nghbr;
    int     error;

    error = ft_check_nb_blocs(*buffer);
    table_voisin = ft_table_int(4, 4);
    sum_nghbr = ft_table_neighbours(table_voisin, *buffer);
    if (sum_nghbr != 6 && sum_nghbr != 8)
    {
        error = 1;
        return (error);
    }
    return (error);
}