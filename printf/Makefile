# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 10:54:46 by smendez-          #+#    #+#              #
#    Updated: 2024/11/27 17:17:25 by smendez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_isformat.c ft_nbrchardechex.c ft_printf.c \ 
	ft_sizenbr_base.c ft_strlen.c ft_adresschar.c \
	ft_nbrchardec.c ft_print_adress.c ft_printf.h \
	ft_putstr_fd.c ft_straddend.c ft_strlennull.c
       
OBJS = $(SRC:.c=.o)


NAME = libftprintf.a
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

