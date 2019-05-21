/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:38:26 by mdavid            #+#    #+#             */
/*   Updated: 2019/05/21 14:33:26 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    if (!(table = (int**)ft_memalloc(sizeof(int*) * nb_l)))
        return (-1);
    while (i <= nb_l)
    {
        if (!(table[i] = (int*)ft_memalloc(sizeof(int) * nb_c)))
        {
            while (i >= 0)
            {
                free (table[i]);
                free (table);
            }
            return (-1);
        }
        i++;
    }
    return (table)
}