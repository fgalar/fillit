/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 02:39:51 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/06 03:08:21 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fillit.h"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl("usage : ./fillit target_file");
		return (0);
	}
	ft_parsing(av);
	return (0);
}
