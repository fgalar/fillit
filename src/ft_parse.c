/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:50:34 by fgarault          #+#    #+#             */
/*   Updated: 2019/05/20 17:40:46 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int     check_form(int fd)
{
    static char *buffer;
    int         ret;
    int         i;
    int         error;
    
    ret = 0;
    error = 0;
    if (!(buffer = (char*)malloc(sizeof(char) * 21)))
        return (0);
    ret = read(fd, buffer, 5 * 4);
    buffer[21] = '\0';
    i = 0;
    while (buffer[i])
    {
        printf("coucou\n");
        while (buffer[i] && i < 4)
        {
            if (buffer[i] == '.' || buffer[i] == '#')
                i++;
            else
                error = 1;
        }
            if ((buffer[i] == '\n' || buffer == '\0') && error == 0)
                i++;
            else
                error = 1;
    }
    return (error);
}


int main(int ac, char **av)
{
    if (ac == 2)
        printf("%d", check_form(*av[1]));
    return (0);
}