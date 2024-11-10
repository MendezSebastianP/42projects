# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 10:54:46 by smendez-          #+#    #+#              #
#    Updated: 2024/11/10 15:26:02 by smendez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(wildcard *.c)

OBJS = $(SRC:.c=.o)
NAME = libft.a
CC = gcc
AR = ar
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(FLAGS) -I./ -c $< -o $@

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

