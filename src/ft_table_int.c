/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:38:26 by mdavid            #+#    #+#             */
/*   Updated: 2019/05/22 14:14:32 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>

/* FONCTION : FT_TABLE_INT_INIT.
 * PARAMETRES : table (tableau de int), nb_l (nb line de table), nb_c (nb column de table).
 * DESCRIPTION :
 *     initialise l'ensemble des éléments de table à 0.
 * RETOUR :
 *     rien.
 */

void    ft_table_int_init(int **table, int nb_l, int nb_c)
{
    int     k;
    int     l;

    k = 0;
    while (k < nb_l)
    {
        l = 0;
        while (l < nb_c)
        {
            table[k][l] = 0;
            l++;
        }
        k++;
    }
}

/* FONCTION : FT_TABLE_INT
 * PARAMETRE(S) : nb_l (nb de lignes) , nb_c (nb de colonnes).
 * DESCRIPTION :
 *     Allocation d'un tableau de int de la taille (nb_c x nb_l) d'un tetramino.
 *     Ce tableau permet de compter le nombre de blocs voisins du bloc considéré.
 *     La condition pour que le tetramino soit valide est que la somme des entiers
 *     présent dans le tableau soit au moins de 6.
 * RETOUR :
 *     NULL s'il y a eu une erreur lors de l'allocation.
 *     un tableau de INT initialisé à 0 sinon.
 */
int     **ft_table_int(int nb_l, int nb_c)
{
    int     **table;
    int     i;
    
    i = 0;
    if (!(table = (int**)malloc(sizeof(int*) * nb_l)))
        return (NULL);
    while (i < nb_l)
    {
        if (!(table[i] = (int*)malloc(sizeof(int) * nb_c)))
        {
            while (--i >= 0)
                free (table[i]);
            free (table);
            return (NULL);
        }
        i++;
    }
    ft_table_int_init(table, nb_l, nb_c);
    return (table);
}