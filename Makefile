NAME = so_lon
CC = cc
# mlx
CFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX = mlx/libmlx.a
SRC = main_tester.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(MLX):
		make -C mlx
$(NAME): $(OBJS) $(MLX)
		$(CC) $(CFLAGS) $(MLX) $(OBJS) -o $(NAME)

# %.o: %.c 
# 	$(CC) $(CFLAGS)  -c $< -o $@
