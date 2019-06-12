# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarault <fgarault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 15:29:33 by mdavid            #+#    #+#              #
#    Updated: 2019/06/12 18:37:30 by fgarault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clear all fclean

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

NAME = fillit

LIBFT = -L./libft/ -lft -I./libft/

SRC_NAME = ft_check.c ft_check_form.c ft_check_nb_blocs.c	    \
		   ft_check_tetramino.c ft_display.c ft_parsing.c		\
		   ft_solve.c ft_table_int.c ft_table_neighbours.c		\
		   init_map.c main.c

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fillit.h

SRC_PATH = ./src
OBJ_PATH = ./obj
INC_PATH = ./include

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))

all: libft $(NAME)

libft:
	$(MAKE) -C libft/
	
$(NAME) : $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	
### Permet de creer les objets en remplaçant la ligne de creation de l'objet au fur et à mesure
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(dir $(OBJ_PATH)/$*) 2> /dev/null || true
	@echo "\033[38;2;0;255;0m[cc]\033[0m: $< -> $@"
	@printf "\e[1A"
	@$(CC) $(CFLAGS) -I./libft -I./$(INC_PATH) -c $< -o $@
	@printf "\e[0K"

norme :
	 norminette $(SRC) $(INCLUDE)

clean :
	rm -rf $(OBJ_PATH)
	$(MAKE) -C libft/ clean

fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C libft/ fclean
	
re : fclean all
