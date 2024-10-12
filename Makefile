NAME = so_long
CC = cc
# CFLAGS = -Wall -Wextra -Werror

UNAME:= $(shell uname)

ifeq ($(UNAME), Darwin)
	MLX_DIR = mlx_mac
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR = mlx_linux
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
endif

MLX = $(MLX_DIR)/libmlx.a
SRC = main_tester.c map_parsing.c controller.c drowing_map.c \
	libft_func.c get_next_line.c 

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(MLX):
		make -C $(MLX_DIR)
$(NAME): $(OBJS) $(MLX)
		$(CC) $(MLX_FLAGS) $(OBJS) -o $(NAME)
		
# $(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

# %.o: %.c 
# 	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -f $(OBGS)

clean_mlx:
	make clean -C $(MLX_DIR)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re