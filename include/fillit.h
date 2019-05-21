/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:42:07 by fgarault          #+#    #+#             */
/*   Updated: 2019/05/20 21:42:47 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
typedef struct      s_list
{
    void            *content;
    int             content_size;
    struct s_list   *next;
}                   t_list;

void    check_form(char **buffer);
int     check_tetramino(char **buffer);
int     check(t_list *s_tetramino);

int     **ft_table_int();
#endif