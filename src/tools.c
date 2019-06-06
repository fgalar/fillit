/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 03:54:07 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/06 04:26:18 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"

int		ft_sqroot(char c)
{
	int		i;
	int		nb_piece;

	i = 1;
	nb_piece = c - 'A';
	ft_putchar(c);
	ft_putchar('\n');
	ft_putnbr(nb_piece);
	ft_putchar('\n');
	while (i * i != nb_piece)
	{
		i++;
		ft_putnbr(i);
	}
	return (i);	
}
