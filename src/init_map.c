/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 03:54:07 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/08 22:33:50 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"

int		map_min(char c)
{
	int		i;
	int		nb_piece;

	i = 1;
	nb_piece = c - 'A';
	while (i * i < nb_piece)
	{
		i++;
		ft_putnbr(i);
		ft_putchar('\n');
	}
	return (i);	
}

char	**init_map(t_mappy *map, char c)
{
	int		i;
	int		j;

	j = 0;
	map->size = map_min(c);
	while (j < map_size)
	{
		i = 0;
		while (i < map->size)
			map[j][i++] = '.';
		j++;
	}
	return (map->size);
}
