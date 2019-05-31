/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:42:07 by fgarault          #+#    #+#             */
/*   Updated: 2019/05/31 23:13:37 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H


typedef struct		s_point
{
	int		y;
	int		x;
}					t_point;

typedef struct      s_list
{
	t_point 		point[4];
	char			c;
	struct s_list   *next;
}					t_tetri;

int     ft_check(int *fd);
int    	check_form(char *buffer);
int     ft_check_nb_blocs(char *buffer);
int    	ft_check_tetramino(char **buffer);
void    ft_table_int_init(int **table, int nb_l, int nb_c);
int     **ft_table_int(int nb_l, int nb_c);
int     ft_blocs_updown(char *buffer, int i);
int     ft_blocs_leftright(char *buffer, int i);
int     ft_table_neighbours(int **table, char *buffer);

#endif
