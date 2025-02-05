# ================== COLORS =====================
GREEN = \033[0;32m
RED   = \033[0;31m
RESET = \033[0m

# ================= COMPILATION =================
NAME    = so_long
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g

# =========== MINI LIBX =========================
MLX_PATH = minilibx-linux
MLX      = $(MLX_PATH)/libmlx.a

# Where your headers live
INCLUDES = -I includes -I $(MLX_PATH)

# ======== SOURCE FILES (via wildcards) =========
# Add/modify as necessary:
SRCS = so_long.c \
       $(wildcard src/*.c) \
       $(wildcard get_next_line/*.c) \
       $(wildcard printf_fd/*.c) \
       $(wildcard includes/*.c)

# ======== OBJECT FILES IN .trash FOLDER ========
TRASH = .trash
OBJS  = $(addprefix $(TRASH)/, $(SRCS:.c=.o))

# =================== RULES =====================

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(MLX_PATH) -lmlx -lXext -lX11 -lGL -lm -o $(NAME)
	@echo "$(GREEN)[OK] $(NAME) built successfully!$(RESET)"

# Build the MiniLibX
$(MLX):
	@$(MAKE) -C $(MLX_PATH)
	@echo "$(GREEN)MiniLibX library compiled.$(RESET)"

# Pattern rule: compile .c to .o into .trash/...
$(TRASH)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled $< -> $@$(RESET)"

# Clean up object files (and the .trash folder)
clean:
	@rm -rf $(TRASH)
	@$(MAKE) -C $(MLX_PATH) clean
	@echo "$(RED)Removed object files and .trash folder.$(RESET)"

# Remove the final binary files
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed $(NAME) binary.$(RESET)"

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re