# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 10:10:32 by smendez-          #+#    #+#              #
#    Updated: 2025/02/12 11:33:39 by smendez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = philo
CC      = gcc
FLAGS   = -Wall -Wextra -Werror
SRC     = philo.c utils1.c utils2.c utils3.c utils4.c utils5.c
DIR     = .trash
OBJS    = $(addprefix $(DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(DIR) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(DIR):
	mkdir -p $(DIR)

$(DIR)/%.o: %.c
	$(CC) $(FLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(DIR)

re: fclean all

.PHONY: all clean fclean re