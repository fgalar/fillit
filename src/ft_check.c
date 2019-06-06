/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:37:00 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/06 14:11:34 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"
#include <stdlib.h>
#include <unistd.h>

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
    while (ret != 0 && nb_tetramino < 26)
    {
        //printf("ici ft_check 1\n");
        if ((ret = read(*fd, buffer, 19)) != 19)
        {
            //printf("ici ft_check 2-- ret = %d\n", ret);
            return (-1);
        }
        //printf("ici ft_check 3\n");
        buffer[20] = '\0';
        //printf("ici ft_check 4\n");
        if (ft_check_form(buffer) == 1)
        {
            //printf("ici ft_check 5-- if test_form\n");
            return (1);
        }
        //printf("ici ft_check 5\n");
        if (ft_check_tetramino(&buffer) == 1)
            return (1);
        //printf("ici ft_check 6\n");
        if ((ret = read(*fd, buf_n, 1)) == 1)
            if (buf_n[0] != '\n')
                return (1);
        //ft_parsing(buffer)
        nb_tetramino++;
    }
    return (nb_tetramino);
}