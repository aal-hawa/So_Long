NAME = so_lon
CC = cc
CFLAGS = -Wall -Wextra -Werror  -Imlx

SRC = main_tester.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@
