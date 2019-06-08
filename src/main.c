/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 02:39:51 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/07 03:30:26 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fillit.h"

int		main(int ac, char **av)
{
	char	map[26][26];
	t_tetri *tromimi;
	int		size;

	size = 2;	 
	if (ac != 2)
	{
		ft_putendl("usage : ./fillit target_file");
		return (0);
	}
	tromimi = ft_parsing(av);
	
	ft_place(tromimi, map, size);
	return (0);
}
