NAME = so_long
SRC = $(addprefix srcs/, main.c)
OBJ := $(SRC:%.c=%.o)

CC = cc
CCFLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	cc $(CCFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	make clean -C mlx/
	rm -f $(NAME)

re : fclean all
