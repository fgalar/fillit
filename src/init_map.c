/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 03:54:07 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/10 23:42:54 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../libft/libft.h"
#include "../include/fillit.h"

int		map_min(int size)
{
	int		i;

	i = 1;
	size *= 4;
	while (i * i < size)
		i++;
	return (i);	
}

char	**mapper(int size)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
		
	if (!(map = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	map[size] = 0;
	while (j < size)
	{
		if (!(map[j] = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		map[j][size] = '\0';
		i = 0;
		while (i < size)
		{	
			map[j][i] = '.';
			i++;
		}
		j++;
	}
	return (map);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	t_mappy	*map;
	int		y;
	int		x;
	int     max;

	y = 0;
	x = 0;
	map = (t_mappy*)malloc(sizeof(t_mappy));
	max = map_min(26);
	map = mapper(map, max);
	while (y < max)
	{
		ft_putstr(map->map[y]);
		ft_putchar('\n');
		y++;
	}
	return (0);
}*/
