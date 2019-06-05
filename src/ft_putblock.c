/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putblock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 00:46:40 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/05 05:41:31 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fillit.h"
#include "../libft/libft.h"



void	display(t_mappy map)
{
	int		y;

	y = 0;
	while (y < 26)
	{
		ft_memset(map.map[y], '.', 25);
		map.map[y][25] = '\0';
		ft_putstr(map.map[y]);
		ft_putchar('\n');
		y++;
	}
}

void	put_tetri(t_tetri *element, )
{
		while ()
}



int main()
{
	t_mappy map;
	int		i;
	
	i = 0;
	while (i < 26)
	{
		ft_bzero(map.map, 26);
		i++;
	}
	display(map);
	return (0);
}

