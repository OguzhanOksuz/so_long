NAME = so_long
BNAME = so_long_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

FRAEMWORKS=-framework OpenGL -framework AppKit
ARCS = ./mlx/libmlx.a

BSRCS =	utils.c					\
		init_map.c				\
		ft_split.c				\
		is_reachable.c			\
		map_counter_bonus.c		\
		init_images_bonus.c		\
		init_structs_bonus.c	\
		render_engine_bonus.c	\
		drawer_bonus.c			\
		physics_engine_bonus.c	\
		move_map_bonus.c		\
		animation_engine.c		\
		patrol_engine.c			\
		hud_render.c			\
		ft_itoa.c				\
		bonus.c

SRCS =	utils.c				\
		ft_split.c			\
		is_reachable.c		\
		init_map.c			\
		init_structs.c		\
		init_images.c		\
		physics_engine.c	\
		map_counter.c		\
		render_engine.c		\
		move_map.c			\
		drawer.c			\
		hud_render.c		\
		ft_itoa.c			\
		main.c

BOBJS = $(BSRCS:.c=.o)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: $(BNAME)

$(BNAME): $(ARCS) $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) $(FRAEMWORKS) $(ARCS) -o $(BNAME)

$(NAME): $(ARCS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FRAEMWORKS) $(ARCS) -o $(NAME)

$(ARCS):
	@make -C mlx/ all

clean:
	rm -rf $(BOBJS)
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(ARCS)
	rm -rf $(NAME)
	rm -rf $(BNAME)


re: fclean all

.PHONY: all clean fclean re bonus 
