# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 11:15:59 by akaplyar          #+#    #+#              #
#    Updated: 2017/06/24 17:33:02 by akaplyar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = lem_in.h

LIB_HEADER = $(LIB_PATH)libft.h

CC = @gcc

LIB_PATH = ./libft/

CFLAGS = -Wall -Wextra -Werror

MAKE_LIB = $(MAKE) -C $(LIB_PATH)

OBJ = main.o reader.o operator.o checker.o hasher.o\
    options.o utils.o finder.o best_opt.o ants.o print_out.o

.PHONY: clean fclean re

NAME = lem_in

all:  lib $(OBJ) $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(OBJ) -I $(HEADER) $(LIB_PATH)libft.a
	@echo "\x1B[32m\0lem_in created\x1B[0m\0"

$(OBJ): $(HEADER)

lib:
#	$(MAKE_LIB)

clean:
#	$(MAKE_LIB) clean
	@rm -rf $(OBJ)
	@echo "\x1B[31m\0lem_in objects cleared\x1B[0m\0"

fclean: clean
#	$(MAKE_LIB) fclean
	@rm -rf $(NAME)
	@echo "\x1B[31m\0lem_in deleted\x1B[0m\0"

re: fclean all
