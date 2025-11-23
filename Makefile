NAME = so_long
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined
SRCS = srcs/parser.c srcs/checks.c srcs/main.c srcs/utils.c 
OBJS =  srcs/parser.o srcs/checks.o srcs/main.o srcs/utils.o
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

all: ascii $(MLX_LIB) $(LIBFT) $(NAME)

ascii:
	@echo "\033[1;36m"
	@echo "  _________          .____                                      "
	@echo " /   _____/ ____     |    |    ____   ____    ____              "
	@echo " \_____  \ /  _ \    |    |   /  _ \ /    \  / ___\             "
	@echo " /        (  <_> )   |    |__(  <_> )   |  \/ /_/  >            "
	@echo "/_______  /\____/____|_______ \____/|___|  /\___  /             "
	@echo "        \/     /_____/       \/          \//_____/              "
	@echo "\033[1;33m"
	@echo "    ___   __           .__                               ___    "
	@echo "   /  / _/  |_  ____   |  | _____ _______  ____   ____   \  \   "
	@echo "  /  /  \   __\/  _ \  |  | \__  \\_  __ \/ ___\ /  _ \   \  \  "
	@echo " (  (    |  | (  <_> ) |  |__/ __ \|  | \/ /_/  >  <_> )   )  ) "
	@echo "  \  \   |__|  \____/  |____(____  /__|  \___  / \____/   /  /  "
	@echo "   \__\                          \/     /_____/          /__/   "
	@echo "\033[1;31m"
	@echo "             	   by dajose-p                "
	@echo "\033[0m"
	@echo "\033[92mCompilando so_long, por favor espere...\033[0m"

compile: .compile_stamp 
.compile_stamp:
	@echo "\033[92mCompilando...\033[0m"; \
	for i in $$(seq 1 100); do \
		printf "\033[94m\r[%-100s] $$((i * 1))%%\033[0m" $$(head -c $$i < /dev/zero | tr '\0' '#'); \
		sleep 0.05; \
	done; \
	echo "\n\033[92mCompilación completada.\033[0m"
	@touch .compile_stamp

$(LIBFT):
	@make -C $(LIBFT_DIR) > /dev/null 2>&1

$(MLX_LIB):
	@cd $(MLX_DIR) && ./configure > /dev/null 2>&1

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lmlx_Linux -lXext -lX11 -L mlx/ -o $(NAME) > /dev/null 2>&1 & \
	$(MAKE) --no-print-directory compile

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null 2>&1

clean:
	@rm -f $(OBJS) > /dev/null 2>&1
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@cd $(MLX_DIR) && make clean || true > /dev/null 2>&1
	@rm -rf .compile_stamp

fclean: clean
	@rm -f $(NAME) > /dev/null 2>&1
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@cd $(MLX_DIR) && make clean > /dev/null 2>&1 || true > /dev/null 2>&1

play: all
	@clear > /dev/null 2>&1
	./so_long "maps/map1.ber"
	@clear > /dev/null 2>&1
	./so_long "maps/map2.ber"
	@clear > /dev/null 2>&1
	./so_long "maps/map3.ber" 
	@clear > /dev/null 2>&1
	./so_long "maps/map4.ber"
	@clear > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re ascii progress
