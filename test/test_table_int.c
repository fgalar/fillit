/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_table_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:16:28 by mdavid            #+#    #+#             */
/*   Updated: 2019/05/22 16:31:30 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../fillit.h"

int     main(void)
{
    int     **table;
    int     nb_c = 4, nb_l = 4;
    int     i;
    int     j;

    i = 0;
    j = 0;
    table = ft_table_int(nb_l, nb_c);
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            printf("  [%d]", table[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    /*printf("[%d] [%d] [%d] [%d]\n", table[0][0], table[0][1], table[0][2], table[0][3], table[0][10]);
    printf("[%d] [%d] [%d] [%d]\n", table[1][0], table[1][1], table[1][2], table[1][3], table[1][4]);
    printf("[%d] [%d] [%d] [%d]\n", table[2][0], table[2][1], table[2][2], table[2][3], table[2][4]);
    printf("[%d] [%d] [%d] [%d]\n", table[3][0], table[3][1], table[3][2], table[3][3], table[3][4]);
    printf("[%d] [%d] [%d] [%d]\n", table[4][0], table[4][1], table[4][2], table[4][3], table[4][4]);*/
    return (0);
}