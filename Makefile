NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

FRAEMWORKS=-framework OpenGL -framework AppKit
ARCS = ./mlx/libmlx.a

PASE = 	render_engine.c		\
	image_put_engine.c	\

SRCS =	utils.c			\
	ft_split.c		\
	is_reachable.c		\
	init_map.c		\
	init_structs.c		\
	init_images.c		\
	physics_engine.c	\
	map_counter.c		\
	debugger.c		\
	move_map.c		\
	main.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(FRAEMWORKS) $(ARCS) -o $(NAME)

$(ARCS):
	@make -C mlx/ all

clean:

fclean:
	rm -rf $(NAME)


re: fclean all


.PHONY: all clean fclean re
