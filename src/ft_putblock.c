/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putblock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 00:46:40 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/08 22:30:44 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fillit.h"
#include "../libft/libft.h"

void	can_put(t_tetri *piece, t_mappy *map, int i, int j)
{
	int		place;

	place = 0;
	while (i < 4)
	{
		if (map[j + piece->point[place].y][i + piece->point[place].x] != '.')
			return (1);

	}
}

void ft_princ()
{
	
}

