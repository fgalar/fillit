/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 02:39:51 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/10 23:59:26 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fillit.h"

int		main(int ac, char **av)
{
	t_tetri *tromimi;
	t_mappy	map;
	if (ac != 2)
	{
		ft_putendl("usage : ./fillit target_file");
		return (0);
	}
	
	tromimi = ft_parsing(av[1]);
	
	map.size_map = map_min(3); // retour ft_check
	if (!(map.map = mapper(26)))
		return (-1);
	while (!(bck_trck_bitch(tromimi, map)))
		(map.size_map)++;
	ft_display(map);
	return (0);
}
