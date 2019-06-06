/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:55:35 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/06 13:07:28 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../libft/libft.h"

void    ft_prt_solution(char **solution)
{
    int     i;

    i = 0;
    while (*solution[i])
    {
        ft_putendl(solution[i]);
        i++;
    }
}