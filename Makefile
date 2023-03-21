NAME = so_long
BNAME = so_long_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

FRAEMWORKS=-framework OpenGL -framework AppKit
ARCS = ./mlx/libmlx.a

BSRCS = bonus.c			\
	utils.c			\
	utils_bonus.c		\
	is_reachable.c		\
	init_map.c		\
	physics_engine_bonus.c	\
	init_structs_bonus.c	\
	drawer_bonus.c		\
	ft_split.c		\
	init_images_bonus.c	\
	map_counter_bonus.c	\
	render_engine_bonus.c	\
	move_map.c

SRCS =	utils.c			\
	ft_split.c		\
	is_reachable.c		\
	init_map.c		\
	init_structs.c		\
	init_images.c		\
	physics_engine.c	\
	map_counter.c		\
	render_engine.c		\
	move_map.c		\
	drawer.c		\
	main.c

all: $(NAME)

bonus: $(BNAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(FRAEMWORKS) $(ARCS) -o $(NAME)

$(BNAME):
	$(CC) $(CFLAGS) $(BSRCS) $(FRAEMWORKS) $(ARCS) -o $(NAME)


$(ARCS):
	@make -C mlx/ all

clean:

fclean:
	rm -rf $(NAME)


re: fclean all

bre: fclean bname

.PHONY: all clean fclean re
