/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putblock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 00:46:40 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/06 01:44:42 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fillit.h"
#include "../libft/libft.h"



void	display(char	map[26][26])
{
	int		y;

	y = 0;
	while (y < 26)
	{
		ft_memset(map[y], '.', 25);
		map[y][25] = '\0';
		ft_putstr(map[y]);
		ft_putchar('\n');
		y++;
	}
}

void	put_tetri(t_tetri *element, char map[26][26])
{
		int		y;
		int		x;
		
		y = 0;
		while (map[y])
		{
			x = 0;
			while (map[y][x] == '.')
				map[
			y++;
		}
}



int main()
{
	char	map[26][26];
	int		i;
	
	i = 0;
	display(map);
	return (0);
}

