# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 13:39:43 by osokoliu          #+#    #+#              #
#    Updated: 2018/05/24 14:32:31 by osokoliu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lemin

FILE_C =  main.c ft_ant.c ft_start_end.c ft_room.c ft_link.c ft_node.c ft_way.c

FILE_O = $(FILE_C:.c=.o)

GCC = gcc

FLAG = -g -Wall -Wextra -Werror

LIB_INC = -I libft/

LIBNAME = ./libft/libft.a

all: $(NAME)

$(LIBNAME): ./libft/libft.h
	make -C ./libft

$(NAME): $(LIBNAME) $(FILE_O)
	$(GCC) $(FILE_O) ./libft/libft.a -o $(NAME)

%.o: %.c
	$(GCC) $(FLAG) -c $< $(LIB_INC)

clean:
	make -C ./libft clean
	rm -f $(FILE_O)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
	make -C ./libft fclean