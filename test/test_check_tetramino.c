/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check_tetramino.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:30:25 by mdavid            #+#    #+#             */
/*   Updated: 2019/05/22 18:31:56 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"
#include <stdio.h>

int     main(void)
{
    char    *buffer="####\n....\n....\n....\n";

    printf("val de check_tetramino : %d\n", ft_check_tetramino(&buffer));
    return (0);
}