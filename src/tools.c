/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 03:54:07 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/06 05:42:48 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"

int		ft_sqroot(char c)
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
