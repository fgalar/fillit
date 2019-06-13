/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 19:11:15 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/13 20:53:56 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/fillit.h"
#include "../libft/libft.h"


int     main(int ac, char **av)
{
    int         fd;
    int         nb_tetri;
    t_tetri     *lst_tetri;
	t_mappy		map;

    nb_tetri = 0;
    fd = open(av[1], O_RDONLY);
    if (ac != 2)
    {
        ft_putendl("usage :");
        return (-1);
    }
    if (fd == -1)
    {
        ft_putendl("error");
        return (-1);
    }
    nb_tetri = ft_check(&fd);
    close(fd);
    if (nb_tetri > 0)
        lst_tetri = ft_parsing(av[1]);
	map.size_map = map_min(nb_tetri);
    if (!(map.map = mapper(26)))
		return (-1);
	while (!(bck_trck(lst_tetri, map)))
		(map.size_map)++;
	ft_display(map);
	return (0);
} 
