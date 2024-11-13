# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 10:54:46 by smendez-          #+#    #+#              #
#    Updated: 2024/11/13 11:06:56 by smendez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

BONUS_SRC = $(wildcard *_bonus.c)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

NAME = libft.a
CC = gcc
AR = ar
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) rcs $(NAME) $(BONUS_OBJS)

%.o:%.c
	$(CC) $(FLAGS) -I./ -c $< -o $@

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

