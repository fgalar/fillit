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
#include "../include/fillit.h"

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

t_mappy	*init_map(t_mappy *map, char c)
{
	int		i;
	int		j;

	j = 0;
	map->size = map_min(c);
	while (j < map->size)
	{
		i = 0;
		while (i < map->size)
			map->map[j][i++] = '.';
		j++;
	}
	return (map->map);
}

int	main(void)
{
	t_mappy	*map;
	int	y;
	int     max;

	y = 0;
	max = map_min('E');
	map = init_map(map, 'E');
	while (y < max)
	{
		ft_putstr(*map[y]);
		y++;
	}
	return (0);
}
