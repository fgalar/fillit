/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:38:26 by mdavid            #+#    #+#             */
/*   Updated: 2019/05/20 21:42:36 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* FONCTION : FT_TABLE_INT
 * PARAMETRE(S) : aucun
 * DESCRIPTION :
 *     Allocation d'un tableau de int de la taille (4x4) d'un tetramino.
 *     Ce tableau permet de compter le nombre de blocs voisins du bloc considéré.
 *     La condition pour que le tetramino soit valide est que la somme des entiers
 *     présent dans le tableau soit au moins de 6.
 * RETOUR :
 *     NULL s'il y a eu une erreur lors de l'allocation.
 *     un tableau de INT initialisé à 0 sinon.
 */
int     **ft_table_int()
{
    int     **table;

    if (!(table = (int**)ft_memalloc(sizeof(int*) * 4)))
        return (-1);
    while (i <= 3)
    {
        if (!(table[i] = (int*)ft_memalloc(sizeof(int) * 4)))
        {
            while (i >= 0)
                free (table[i]);
                free (table);
            return (-1);
        }
    }
    return (table)
}