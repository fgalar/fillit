/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 03:54:07 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/13 20:49:37 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../include/fillit.h"

void    ft_free_grid(char **grid)
{
	int     i;

	i = 0;
	if (grid)
	{
		while (grid[i])
		{
			free(grid[i]);
			i++;
		}
		free(grid);
		grid = NULL;
	}
}

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
		while (i <= size)
		{
			map[j][i] = '.';
			i++;
		}
		j++;
	}
	return (map);
}
