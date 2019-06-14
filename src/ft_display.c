/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 21:30:55 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/12 18:19:03 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../libft/libft.h"

void	ft_display(t_mappy map)
{
	int		j;
	int		i;

	j = 0;
	while (j < map.size_map)
	{
		i = 0;
		while (i < map.size_map)
			ft_putchar(map.map[j][i++]);
		ft_putchar('\n');
		j++;
	}
}
