/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 19:11:15 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/14 13:24:18 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/fillit.h"
#include "../libft/libft.h"

static int	ft_error(int ac, int fd)
{
	int		nb_tetri;

	if (ac != 2)
	{
		ft_putendl("usage : ./fillit [input file]");
		return (-1);
	}
	if (fd == -1 || ((nb_tetri = ft_check(&fd)) == -1))
	{
		ft_putendl("error");
		return (-1);
	}
	return (nb_tetri);
}

int			main(int ac, char **av)
{
	int		fd;
	int		nb_tetri;
	t_tetri	*lst_tetri;
	t_mappy	map;
	int		bool_c;

	fd = open(av[1], O_RDONLY);
	bool_c = 1;
	if ((nb_tetri = ft_error(ac, fd)) == -1)
		return (0);
	lst_tetri = ft_parsing(av[1]);
	map.size_map = map_min(nb_tetri);
	if (!(map.map = mapper(26)))
		return (-1);
	while (!(bck_trck(lst_tetri, map)))
		(map.size_map)++;
	bool_c == 1 ? ft_display(map) : ft_display_unicorn(map);
	return (0);
}
