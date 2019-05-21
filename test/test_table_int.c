/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_table_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:16:28 by mdavid            #+#    #+#             */
/*   Updated: 2019/05/21 16:03:53 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int     **ft_table_int(int nb_c, int nb_l);
void    ft_table_int_init(int **table);

int     main(void)
{
    int     **table;
    int     nb_c = 4, nb_l = 4;
    int     i;
    int     j;

    i = 0;
    j = 0;
    table = ft_table_int(nb_l, nb_c);
    /*while (table[i])
    {
        j = 0;
        while (table[i][j])
        {
            printf("  [%d]", table[i][j]);
            j++;
        }
        i++;
    }*/
    printf("[%d] [%d] [%d] [%d]\n", table[0][0], table[0][1], table[0][2], table[0][3]);
    printf("[%d] [%d] [%d] [%d]\n", table[1][0], table[1][1], table[1][2], table[1][3]);
    printf("[%d] [%d] [%d] [%d]\n", table[2][0], table[2][1], table[2][2], table[2][3]);
    printf("[%d] [%d] [%d] [%d]\n", table[3][0], table[3][1], table[3][2], table[3][3]);
    return (0);
}