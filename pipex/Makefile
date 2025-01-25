SRC = \
	pipex.c \
	get_next_line.c get_next_line_utils.c \
	outils1.c \
	outils2.c \
	outils3.c \
	outils4.c \
	outils5.c \
	outils6.c \
	ft_printf_fd1.c ft_printf_fd2.c ft_printf_fd3.c ft_printf_fd4.c \
	ft_split.c ft_split2.c

BSRC = \
	get_next_line.c get_next_line_utils.c \
	outils1.c \
	outils2.c \
	outils3.c \
	outils4.c \
	outils5.c \
	outils6.c \
	ft_printf_fd1.c ft_printf_fd2.c ft_printf_fd3.c ft_printf_fd4.c \
	ft_split.c ft_split2.c \
	pipex_bonus.c

OBJS        = $(SRC:.c=.o)
BONUS_OBJS  = $(BSRC:.c=.o)

NAME        = pipexx
NAME_B      = pipex
CC          = gcc
AR          = ar
FLAGS       = -Wall -Wextra -Werror -g

all: $(NAME) $(NAME_B)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(BONUS_OBJS)
	$(CC) $(FLAGS) $(BONUS_OBJS) -o $(NAME_B)

%.o: %.c
	$(CC) $(FLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus