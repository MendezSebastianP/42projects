# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 10:54:46 by smendez-          #+#    #+#              #
#    Updated: 2024/11/20 19:17:59 by smendez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
       ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
       ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
       ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
       ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
       ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
       ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
       ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
       ft_putnbr_unsigned_fd.c ft_putnbr_base.c \
       ft_print_adress.c ft_sizenbr_base.c
       
BSRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c \
	ft_lstmap_bonus.c
OBJS = $(SRC:.c=.o)

BONUS_SRC = $(BSRC:.c=.o)
BONUS_OBJS = $(BSRC:.c=.o)

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
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

