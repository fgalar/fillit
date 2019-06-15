/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:37:00 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/15 18:45:51 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/fillit.h"

/* FONCTION : CHECK
 * PARAMETRE(S) : int fd     |le file descriptor du fichier contenant les tetraminos|
 * DESCRIPTION : 
 *     La fct vérifie l'intégralité du fichier supposé contenir les tetraminos
 * RETOUR :
 *     error = -1/0/1 -> -1 = il y a eu un pb d'allocation ou lecture, 
 *                        0 = le fichier contenant les tetraminos est valide
 *                        1 = le fichier contenant les tetraminos est invalide.
 */
int     ft_check(int *fd)
{
    char        *buffer;
    char        buf_n[1]="a";
    int         ret;
    int         nb_tetramino;

    ret = 3;
    nb_tetramino = 0;
    if (read(*fd, buf_n, 0) == -1 || !(buffer = (char*)malloc(sizeof(char) * 21)))
        return (-1);
    buffer[20] = '\0';
    while (ret != 0 && nb_tetramino <= 26)
    {
		if ((ret = read(*fd, buffer, 20)) != 20 || ft_check_form(buffer) == 1
				|| ft_check_tetramino(&buffer) == 1)
		{
			free (buffer);
			return (-1);
		}
        if ((ret = read(*fd, buf_n, 1)) == 1)
            if (buf_n[0] != '\n')
                return (-1);
        nb_tetramino++;
    }
	free(buffer);
    return (nb_tetramino == 0 || nb_tetramino > 26 ? -1 : nb_tetramino);
}
