NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

UNAME:= $(shell uname)

MLX_DIR = mlx_mac
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
SRC_MANDATORY = main_mandatory.c 
SRC_BONUS = main_bonus.c 

MLX = $(MLX_DIR)/libmlx.a
SRC = map_parsing.c controller.c drowing_map.c \
	libft_func.c get_next_line.c  print_nump.c drowing_map_utils.c \
	flood_fill.c map_parsing_utils.c print_str.c

OBJS = $(SRC:.c=.o)
OBJS_MANDATORY = $(SRC_MANDATORY:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
all: $(NAME)

$(MLX):
		make -C $(MLX_DIR)

$(NAME): $(OBJS) $(OBJS_MANDATORY) $(MLX)
		$(CC) $(MLX_FLAGS) $(OBJS) $(OBJS_MANDATORY) -o $(NAME)

$(NAME_BONUS): $(OBJS) $(OBJS_BONUS) $(MLX)
		$(CC) $(MLX_FLAGS) $(OBJS) $(OBJS_BONUS) -o $(OBJS_BONUS)

%.o: %.c 
	$(CC) $(CFLAGS)  -c $< -o $@

bonus: $(NAME_BONUS)

clean:
	rm -f $(OBJS)

clean_mlx:
	make clean -C $(MLX_DIR)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus 