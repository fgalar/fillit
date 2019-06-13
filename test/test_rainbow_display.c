/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rainbow_display.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:36:09 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/13 19:47:51 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include "../include/fillit.h"
#include "../libft/libft.h"


int     main(void)
{
    char    **solution;
    int     i;

    i = 0;
    solution = (char**)malloc(sizeof(char*) * 6);
    while (i < 6)
    {
        solution[i] = (char*)malloc(sizeof(char) * 6);
        i++;
    }
    solution[0] = "ABBC.";
    solution[1] = "A.BCC";
    solution[2] = "A.BC.";
    solution[3] = "ADD..";
    solution[4] = "..DD.";
    solution[5] = NULL;
    ft_prt_solution(solution);
    return (0);
}