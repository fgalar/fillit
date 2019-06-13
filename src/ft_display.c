/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 21:30:55 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/13 21:00:47 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fillit.h"
#include "../libft/libft.h"


void    ft_rainbow(char **color)
{
	int     	i;
	i = 0;
	color = (char**)malloc(sizeof(char*) * 27);
	while (i < 27)
	{
		color[i] = (char*)malloc(sizeof(char) * 34);
		color[i][33]='\0';
		i++;
	}
}

void	ft_display(t_mappy map)
{
	int		j;
	int		i;
	static char	*unicorn[27] = {POINT, A, B, C, D, E, F, G, H, I, J, K, L, M,
		N, O, P, Q, R, S, T U, V, W, X, Y, Z};

	j = 0;
	while (j < map.size_map)
	{
		i = -1;
		while (++i < map.size_map)
		{
			k = 0;
			while (map.map[j][i] != unicorn[k])
			ft_putchar(map.map[j][i++]);
		}
		ft_putchar('\n');
		j++;
	}
}
