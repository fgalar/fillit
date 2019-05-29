/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:35:59 by mdavid            #+#    #+#             */
/*   Updated: 2019/05/22 21:23:45 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int     main(int ac, char **av)
{
    int     fd;
    int     error;

    error = 5;
    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        error = ft_check(&fd);
        printf("retour de ft_check:%d\n", error);
        close(fd);
    }
    return (0);
}