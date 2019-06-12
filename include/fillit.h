/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:42:07 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/12 18:02:22 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef struct      s_tetri
{
	t_point			point[4];
	char			c;
	struct s_tetri	*next;
}					t_tetri;

int    		ft_check_form(char *buffer);
void    	ft_table_int_init(int **table, int nb_l, int nb_c);
int     	**ft_table_int(int nb_l, int nb_c);
int     	ft_blocs_updown(char *buffer, int i);
int     	ft_blocs_leftright(char *buffer, int i);
int     	ft_table_neighbours(int **table, char *buffer);
int     	ft_check_nb_blocs(char *buffer);
int    		ft_check_tetramino(char **buffer);
int     	ft_check(int *fd);
void		ft_set_point(char *buffer, t_tetri *new_element);
t_tetri		*lstadd(char *buffer, t_tetri *element, char c);
t_tetri		*ft_parsing(char **av);
void    	ft_find_trsl(t_tetri *piece, int *trsl_x, int *trsl_y);
void    	ft_apply_trsl(t_tetri *piece, int *trsl_x, int *trsl_y);
void		ft_check3(t_tetri *tetri);
int     	ft_sqrt(int nb);
void    	fill_with_point(char ***grid);
char    	**ft_grid(int size);
int			ft_offset_tetra(t_tetri *tetri, char **grid, int *dx, int *dy);
void    	ft_place_1tetra(t_tetri *tetri, char ***grid, int dx, int dy);
int     	ft_put_all_tetra(t_tetri *lst_tetri, char ***grid, int size);
char		**ft_backtrack(t_tetri *lst_tetri, int nb_tetri);
void		ft_prt_solution(char **solution);

#endif
