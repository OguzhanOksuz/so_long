NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =	utils.c		\
	init_map.c


all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:


fclean:
	rm -rf $(NAME)


re: fclean all


.PHONY: all clean fclean re
