# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarault <fgarault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 15:29:33 by mdavid            #+#    #+#              #
#    Updated: 2019/06/16 14:11:46 by mdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clear all fclean

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = fillit

LIBFT_L = -L./libft/ -lft -I./libft/

LIBFT = ./libft/libft.a

SRC_NAME =	ft_parsing.c			\
			ft_check.c				\
			ft_check_form.c			\
			ft_check_nb_blocs.c		\
			ft_check_tetramino.c	\
			ft_display.c			\
			ft_solve.c				\
			ft_table_int.c			\
			ft_table_neighbours.c	\
			init_map.c				\
			main.c

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fillit.h

SRC_PATH = ./src
OBJ_PATH = ./obj
INC_PATH = ./include

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))

all: $(NAME)

$(LIBFT):
	@echo "\033[1;31m[LIBFT RULE]\033[0m \033[1;33mcompilation libft\033[0m"
	@make -C libft
	
### Permet de creer les objets en remplaçant la ligne de creation de l'objet au fur et à mesure
##	printf "\e[1A"
##	printf "\e[0K"
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $(OBJ_PATH)/$*)
	@echo "\033[1;32m[$(CC)] - [$(CFLAGS)]\033[0m \033[1;33min progress ...:\033[0m $< \033[1;31m->\033[0m $@"
	@printf "\e[1A"
	@$(CC) $(CFLAGS) -I./$(INC_PATH) -c $< -o $@
	@printf "\e[0K"

$(NAME) : $(LIBFT) $(OBJ)
	@echo "\033[1;32m[$(CC)] - [$(CFLAGS)]\033[0m \033[1;33m- generating executable - :\033[0m $@"
	@echo "\033[1;31m--->\033[0m $(CC) $(CFLAGS) $(OBJ) $(LIBFT_L) -I$(INC_PATH) -o $(NAME)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_L) -I$(INC_PATH) -o $(NAME)

norme :
	 norminette -R CheckForbiddenSourceHeader $(SRC) $(INCLUDE)

clean :
	@echo "\033[1;31m[CLEAN RULE]\033[0m \033[1;33mdeleting objects directory\033[0m"
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;31m[LIBFT CLEAN RULE]\033[0m \033[1;33mdeleting libft objects\033[0m"
	@make -C libft/ clean

fclean : clean
	@echo "\033[1;31m[FCLEAN RULE]\033[0m \033[1;33mdeleting fillit executable\033[0m"
	@rm -rf $(NAME)
	@echo "\033[1;31m[LIBFT FCLEAN RULE]\033[0m \033[1;33mdeleting libft objects and libft.a\033[0m"
	@make -C libft/ fclean
	
re : fclean all

