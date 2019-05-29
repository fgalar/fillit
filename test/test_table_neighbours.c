/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_table_neighbours.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:19:35 by mdavid            #+#    #+#             */
/*   Updated: 2019/05/22 17:27:42 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"
#include <stdio.h>

int     main(void)
{
    char    *buffer="###.\n###.\n###.\n....\n";
    int     **tab_voisin;
    int     sum_nghbr;

    printf("tetramino:\n%s\n ~~~~~ \n", buffer);
    sum_nghbr = 0;
    tab_voisin = ft_table_int(4, 4);
    printf("ici\n");
    
    printf("[%d] [%d] [%d] [%d]\n", tab_voisin[0][0], tab_voisin[0][1], tab_voisin[0][2], tab_voisin[0][3]);
    printf("[%d] [%d] [%d] [%d]\n", tab_voisin[1][0], tab_voisin[1][1], tab_voisin[1][2], tab_voisin[1][3]);
    printf("[%d] [%d] [%d] [%d]\n", tab_voisin[2][0], tab_voisin[2][1], tab_voisin[2][2], tab_voisin[2][3]);
    printf("[%d] [%d] [%d] [%d]\n", tab_voisin[3][0], tab_voisin[3][1], tab_voisin[3][2], tab_voisin[3][3]);
    printf("\n\ntable_voisin :\n");
    sum_nghbr = ft_table_neighbours(tab_voisin, buffer);
    printf("\n val de sum_nghbr = %d", sum_nghbr);
    return (0);
}