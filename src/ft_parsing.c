/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:12:14 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/06 05:50:20 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../include/fillit.h"

void	ft_set_point(char *buffer, t_tetri *new_element)
{
	int		i;
	int		y_p;
	int		x_p;
	int		n;

	i = 0;
	y_p = 0;
	x_p = 0;
	n = 0;
	while (buffer[i])
	{
		if (buffer[i] == '#')
		{
			if (n == 0)
			{
				y_p = (i + 1) / 5;
				x_p = (i + 1) % 5;
			}
			new_element->point[n].y = ((i + 1) / 5) - y_p;
			new_element->point[n++].x = ((i + 1) % 5) - x_p;
		}
		i++;
	}
}

t_tetri	*lstadd(char *buffer, t_tetri *element, char c)
{
	t_tetri *start;
	t_tetri *new_element;

	if (!(new_element = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	start = element;
	if (element)
	{
		while (element->next != NULL)
			element = element->next;
		element->next = new_element;
	}
	new_element->c = c;
	ft_set_point(buffer, new_element);
	new_element->next = NULL;
	if (element == NULL)                                                    
		return (new_element);
	return (start);
}

int		ft_parsing(char **av)
{
	int		fd;
	int		ret;
	t_tetri	*lst_tetri;
	char	buffer[21];
	char	c;

	fd = open(av[1], O_RDONLY);
	ret = 0;
	lst_tetri = NULL;
	c = 'A';
	while ((ret = read(fd, buffer, 21)) > 0)
	{
		buffer[ret] = '\0';
		if ((lst_tetri = lstadd(buffer, lst_tetri, c)) == NULL)
			return (-1);
		c++;
	}
	//ft_map(lst_tetri);
	
	int i = 0;
	while (lst_tetri != NULL) {
		i=0;
		while(i < 4) {
			ft_putnbr(lst_tetri->point[i].x);
			ft_putchar('|');
			ft_putnbr(lst_tetri->point[i].y);
			ft_putchar('\n');
			i++;
		}
			ft_putchar('\n');
		lst_tetri = lst_tetri->next;
	}
/*	char	**tab;
	int		i;

	i = 0;
	if (!(tab = ft_tab(lst_tetri, c)))
		return (NULL);
	while (tab[i])
	{
		ft_putstr(tab[i]);
		i++;
	}*/
	return (ft_sqroot(c) * 4);
}
