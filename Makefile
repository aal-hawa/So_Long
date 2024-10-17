NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = mlx_mac
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
SRC_MANDATORY = main_mandatory.c 
SRC_BONUS = main_bonus.c 

MLX = $(MLX_DIR)/libmlx.a
SRC = map_parsing.c controller.c drowing_map.c \
	libft_func.c get_next_line.c  print.c drowing_map_utils.c \
	map_parsing_utils.c so_long_utils.c moving.c 

OBJS = $(SRC:.c=.o)
OBJS_MANDATORY = $(SRC_MANDATORY:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
all: $(NAME)

$(MLX):
		make -C $(MLX_DIR)

$(NAME): $(OBJS) $(OBJS_MANDATORY) $(MLX)
		$(CC) $(MLX_FLAGS) $(OBJS) $(OBJS_MANDATORY) -o $(NAME)

$(NAME_BONUS): $(OBJS) $(OBJS_BONUS) $(MLX)
		$(CC) $(MLX_FLAGS) $(OBJS) $(OBJS_BONUS) -o $(NAME_BONUS)

%.o: %.c 
	$(CC) $(CFLAGS)  -c $< -o $@

bonus: $(NAME_BONUS) 

clean:
	rm -f $(OBJS) $(OBJS_MANDATORY) $(OBJS_BONUS)

clean_mlx:
	make clean -C $(MLX_DIR)

fclean: clean clean_mlx
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus 