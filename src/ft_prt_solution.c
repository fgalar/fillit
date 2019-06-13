/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:55:35 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/13 19:55:25 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/fillit.h"
#include "../libft/libft.h"

void    ft_rainbow(char **color)
{
    int     i;

    i = 0;
    color = (char**)malloc(sizeof(char*) * 27);
        while (i < 27)
        {
            color[i] = (char*)malloc(sizeof(char) * 34);
            color[i][33]='\0';
            i++;
        }
        color[0] = "\033[38;5;15;48;2;192;192;192m.\033[0m";
        color[1] = "\033[38;5;15;48;2;255;102;102mA\033[0m";
	    color[2] = "\033[38;5;15;48;2;255;140;102mB\033[0m";
	    color[3] = "\033[38;5;15;48;2;255;179;102mC\033[0m";
	    color[4] = "\033[38;5;15;48;2;255;217;102mD\033[0m";
	    color[5] = "\033[38;5;15;48;2;255;255;102mE\033[0m";
	    color[6] = "\033[38;5;15;48;2;217;255;102mF\033[0m";
	    color[7] = "\033[38;5;15;48;2;179;255;102mG\033[0m";
	    color[8] = "\033[38;5;15;48;2;140;255;102mH\033[0m";
	    color[9] = "\033[38;5;15;48;2;102;255;102mI\033[0m";
	    color[10] = "\033[38;5;15;48;2;102;255;140mJ\033[0m";
	    color[11] = "\033[38;5;15;48;2;102;255;179mK\033[0m";
	    color[12] = "\033[38;5;15;48;2;102;255;217mL\033[0m";
	    color[13] = "\033[38;5;15;48;2;102;255;255mM\033[0m";
	    color[14] = "\033[38;5;15;48;2;102;217;255mN\033[0m";
	    color[15] = "\033[38;5;15;48;2;102;179;255mO\033[0m";
	    color[16] = "\033[38;5;15;48;2;102;140;255mP\033[0m";
	    color[17] = "\033[38;5;15;48;2;102;102;255mQ\033[0m";
	    color[18] = "\033[38;5;15;48;2;140;102;255mR\033[0m";
	    color[19] = "\033[38;5;15;48;2;179;102;255mS\033[0m";
	    color[20] = "\033[38;5;15;48;2;217;102;255mT\033[0m";
	    color[21] = "\033[38;5;15;48;2;255;102;255mU\033[0m";
	    color[22] = "\033[38;5;15;48;2;255;102;140mV\033[0m";
	    color[23] = "\033[38;5;15;48;2;255;255;255mW\033[0m";
	    color[24] = "\033[38;5;15;48;2;179;179;179mX\033[0m";
	    color[25] = "\033[38;5;15;48;2;102;102;102mY\033[0m";
	    color[26] = "\033[38;5;15;48;2;015;015;015mZ\033[0m";
}

void    ft_prt_solution(char **solution)
{
    int     i;
    int     j;
    t_rainbow   rainbow;

    i = 0;
    printf("ici 1\n");
    ft_rainbow(rainbow.color);
    printf("ici 2\n");
    while (solution[i])
    {
        j = 0;
        printf("ici 3\n");
        while (solution[i][j])
        {
            printf("ici 4\n");
            if (solution[i][j] == '.')
            {
                printf("ici 5\n");
                ft_putstr(rainbow.color[0]);
            }
			else
            {
                printf("ici 6\n");
                printf("%c\n", solution[i][j]);
                printf("%s\n", rainbow.color[1]);
                //printf("%s", rainbow.color[solution[i][j] - 64]);
                //ft_putstr(rainbow.color[1]);
                //ft_putstr(rainbow.color[solution[i][j] - 64]);
            }
            //ft_putstr(solution[i][j]);
            j++;
        }
        i++;
    }
}