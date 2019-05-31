/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:12:14 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/01 00:06:41 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"


t_list	*ft_lstadd(char	*buffer, t_tetri *element, char c)
{
	t_tetri *start;
	t_tetri *new_element;

	if (!(element = (t_tetri*)malloc(sizeof(t_tetri))))
		return (-1);
	start = element;
	if (element)
	{
		while (element != NULL)
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

int		ft_parsing(int ac, char **av)
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
	if (ac != 2)
		return (0);
	while ((ret = read(fd, buffer, 21)) > 0)
	{
		buffer[ret] = '\0';
		if ((lst_tetri = ft_lstadd(buffer, lst_tetri, c)) == -1)
			return (-1);
		c++;
	}	
	return (0);
}
