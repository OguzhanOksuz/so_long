/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:57:37 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/28 18:34:23 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define RES 64

# define WALL_SRC "textures/W.xpm"
# define FLOOR_SRC "textures/F.xpm"
# define EXITA_SRC "textures/EA.xpm"
# define EXITDA_SRC "textures/EDA.xpm"
# define PLAYER_SRC "textures/P.xpm"
# define COIN_SRC "textures/C.xpm"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./mlx/mlx.h"

typedef struct s_map
{
	int		row_len;
	int		row_num;
	int		coins;
	char	**map;
}	t_map;

typedef struct s_coins
{
	int		*coins_c;
	int		**coin_pos;
	int		frame;
	void	*coin_img;
}	t_coins;

typedef struct s_player
{
	int		player_i;
	int		player_j;
	int		frame;
	void	*player_img;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*wall_img;
	void		*floor_img;
	void		**exit_imgs;
	int			move;
	int			res;
	int			*coin;
	int			*player_i;
	int			*player_j;
	int			exit_i;
	int			exit_j;
	char		**m;
	t_map		*map;
	t_coins		*coins;
	t_player	*player;
}	t_game;

t_map	*map_init(char *src);
void	init_images(t_game *game);
void	map_counter(t_map *rt_map);
void	is_reachable(t_map *rt_map);
void	init_structs(t_game *game);
void	try_exit(t_game *game);
void	to_move(t_game *game, int i, int j, int key);
void	to_left(t_game *game);
void	to_down(t_game *game);
void	to_right(t_game *game);
void	to_up(t_game *game);
void	to_collect(t_coins *coins, int i, int j);
void	get_player_cordinates(t_game *game);
void	draw_exit(t_game *g, int i, int j);
void	draw_floor(t_game *g, int i, int j);
void	draw_wall(t_game *g, int i, int j);
void	draw_player(t_game *g, int i, int j);
void	draw_coin(t_game *g, int i, int j);
void	render_map(t_game *game);
void	render_move(t_game *game, int key);
void	render_cordinate(t_game *game, int i, int j);
void	move_count(int num);
void	ft_putnbr(int num);
char	**ft_split(char *str, char c);
char	*ft_read(int fd);
int		ft_strlen(const char *str);
int		ft_strrchr(char *str, int c);
int		ft_strcmp(char *s1, char *s2);
int		error_code(int code);
int		char_counter(t_map *map, char c);

void	print_game(t_game *game);

#endif
