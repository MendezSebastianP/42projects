SRC = \
pipex.c \
get_next_line.c get_next_line_utils.c \
outils1.c \
outils2.c \
outils3.c \
outils4.c \
outils5.c \
ft_split.c ft_split2.c

BSRC = \
pipex_bonus.c

OBJS        = $(SRC:.c=.o)
BONUS_OBJS  = $(BSRC:.c=.o)

NAME        = pipex
CC          = gcc
AR          = ar
FLAGS       = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	$(CC) $(FLAGS) $(OBJS) $(BONUS_OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus