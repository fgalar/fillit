/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_nb_blocs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:05:43 by mdavid            #+#    #+#             */
/*   Updated: 2019/05/31 17:18:31 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"
#include <stdio.h>

/* FONCTION : FT_NB_BLOCS
 * PARAMETRES : char *buffer |chaine de caracteres contenant le possible tetramino|.
 * DESCRIPTION :
 *     La fct vérifie que le possible tetramino est constitué de 4 blocs seulement.
 * RETOUR :
 *     error = 0/1 si le tetramino est valide/invalide.
 */
int     ft_check_nb_blocs(char *buffer)
{
    int     error;
    int     i;
    int     nb_blocs;

    i = 0;
    nb_blocs = 0;
    while (i < 19)
    {
        if (buffer[i] == '#')
            nb_blocs++;
        i++;
    }
    error = (nb_blocs == 4) ? 0 : 1;
    return (error);
}
