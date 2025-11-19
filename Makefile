NAME		= so_long

SRC_DIR		= srcs
OBJ_DIR		= objs
MLX_DIR		= mlx
LIBFT_DIR	= libft

SRC			= $(addprefix $(SRC_DIR)/, \
				main.c checks.c parser.c utils.c \
			)

OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -I./includes -I$(MLX_DIR) -I$(LIBFT_DIR)

MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft

GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@echo "$(GREEN)Compilando libft...$(RESET)"
	@make -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@echo "$(GREEN)Compilando MiniLibX...$(RESET)"
	@make -C $(MLX_DIR) --no-print-directory

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compilando: $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(GREEN)Creando ejecutable $(NAME)...$(RESET)"
	@$(CC) $(OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ Compilación exitosa!$(RESET)"

clean:
	@echo "$(RED)Limpiando archivos objeto...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@make clean -C $(MLX_DIR) --no-print-directory

fclean: clean
	@echo "$(RED)Eliminando ejecutable y librerías...$(RESET)"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) --no-print-directory

re: fclean all

.PHONY: all clean fclean re
