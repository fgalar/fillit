/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:05:53 by mdavid            #+#    #+#             */
/*   Updated: 2019/05/23 11:05:59 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <stdio.h>

int     ft_blocs_leftright(char *buffer, int i);
int     ft_blocs_updown(char *buffer, int i);
int     ft_check_tetramino(char **buffer);
int     ft_check_form(char *buffer);
int     ft_check(int *fd);
int     ft_check_nb_blocs(char *buffer);
int     **ft_table_int(int nb_l, int nb_c);
void    ft_table_int_init(int **table, int nb_l, int nb_c);
int     ft_table_neighbours(int **table, char *buffer);
#endif