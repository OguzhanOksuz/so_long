NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

FRAEMWORKS=-framework OpenGL -framework AppKit
ARCS = ./mlx/libmlx.a

SRCS =	utils.c		\
	ft_split.c	\
	is_reachable.c	\
	init_map.c	\
	init_images.c	\
	main.c

all: $(NAME)

$(NAME):
	@make -C mlx/ all
	$(CC) $(CFLAGS) $(SRCS) $(FRAEMWORKS) $(ARCS) -o $(NAME)

clean:

fclean:
	@make -C mlx/ clean
	rm -rf $(NAME)


re: fclean all


.PHONY: all clean fclean re
