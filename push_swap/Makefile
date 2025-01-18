# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 10:54:46 by smendez-          #+#    #+#              #
#    Updated: 2025/01/18 11:39:38 by smendez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c fun_print1.c fun_print2.c fun_print3.c \
      listfun1.c listfun2.c outils1.c outils2.c \
      push_swap.c swap_fun1.c swap_fun2.c ft_split.c \
      swap_iserror.c swap_outils.c swap_outils2.c swap_outils3.c

OBJS = $(SRC:.c=.o)


NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror -g

$(NAME) :
		$(CC) $(FLAGS) $(SRC) -Includes -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
