/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:50:34 by fgarault          #+#    #+#             */
/*   Updated: 2019/05/21 14:33:23 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../include/fillit.h"

/* FONCTION : CHECK_FORM
 * PARAMETRE(S) : adresse d'une string. 
 * DESCRIPTION :
 *    Reçoit le buffer depuis la fonction CHECK()
 *    Permet de vérifier si le buffer a les caractéristiques d'un tetramino potentiel
 *    en vérifiant que l'on a 4 caracteres ('#'||'.') suivi d'un \n pour les trois 1eres
 *    lignes et d'un '\n'||'\0' pour la derniere ligne.
 * RETOUR :
 *    1 -> le buffer reçu n'a pas la forme d'un potentiel tetramino.
 *    0 -> le buffer reçu a la forme d'un potentiel tetramino.
 */
int    check_form(char **buffer)
{
    int         i;
    int         error;

    i = 0;
    error = 0;
    while (*buffer[i] && i < 19)
    {
        while (*buffer[i] && (ft_mod(i,4) != 0 || i == 0))
        {
            if (*buffer[i] == '.' || *buffer[i] == '#')
                i++;
            else
                error = 1;
        }
            if ((i < 19 && *buffer[i] == '\n') && error == 0)
                i++;
            else
                error = 1;
    }
    if (!(buffer[i] == '\n') || !(buffer[i] == '\0'))
        error = 1;
    return (error);
}

/* FONCTION : CHECK_TETRAMINO
 * PARAMETRE(S) : buffer depuis la fonction CHECK. 
 * DESCRIPTION : 
 *     Permet de vérifier que le possible tetramino réccupéré
 *     est valide.
 * RETOUR :
 *     1 -> Le tetramino est invalide.
 *     0 -> Le tetramino est valide.
 */
int    check_tetramino(char **buffer)
{
    int     **table_voisin;

    table_voisin = ft_table_int(4, 4);
}

/* FONCTION : CHECK
 * PARAMETRE(S) :  
 * DESCRIPTION : 
 *
 * RETOUR :
 * 
 */
int     check(t_list *s_tetramino)
{
    char        *buffer;
    char        buf_n[1];
    int         ret;
    int         error;
    int         fd;

    ret = 0;
    error = 0;
    fd = 0;
    if (!(buffer = (char*)malloc(sizeof(char) * 21)))
        return (-2);
    while (ret != 0)
    {
        if ((ret = read(fd, buffer, 5 * 4)) != 20)
            return (-1);
        buffer[21] = '\0';
        if ((error = check_form(&buffer)) == 0)
        {
            check_tetramino();
        }
        if (!(read(fd, buf_n, 1)))
            return (-1);
        if (buf_n != '\n')
            return (-1);
        if (buf_n == '\n')
            error = 0;               
    }
    return (error);
}

int main(int ac, char **av)
{
    if (ac == 2)
        printf("check forme = %d", check_form(*av[1]));
        printf("check");
    return (0);
}