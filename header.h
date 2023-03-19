/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:57:37 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 18:58:09 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define RES 64

# define BRICK_SRC "textures/envoriment/brick.xpm"
# define PLANK_SRC "textures/envoriment/plank.xpm"
# define PA_SRC "textures/portal/pa.xpm"
# define PDA_SRC "textures/portal/pda.xpm"
# define S0_SRC "textures/steve/s0.xpm"
# define S1_SRC "textures/steve/s1.xpm"
# define S2_SRC "textures/steve/s2.xpm"
# define S3_SRC "textures/steve/s3.xpm"
# define S4_SRC "textures/steve/s4.xpm"
# define S5_SRC "textures/steve/s5.xpm"
# define S6_SRC "textures/steve/s6.xpm"
# define S7_SRC "textures/steve/s7.xpm"
# define S8_SRC "textures/steve/s8.xpm"
# define S9_SRC "textures/steve/s9.xpm"
# define S10_SRC "textures/steve/s10.xpm"
# define S11_SRC "textures/steve/s11.xpm"
# define E0_SRC "textures/dragon/e0.xpm"
# define E1_SRC "textures/dragon/e1.xpm"
# define E2_SRC "textures/dragon/e2.xpm"
# define E3_SRC "textures/dragon/e3.xpm"
# define E4_SRC "textures/dragon/e4.xpm"
# define E5_SRC "textures/dragon/e5.xpm"
# define E6_SRC "textures/dragon/e6.xpm"
# define D0_SRC "textures/diamond/d0.xpm"
# define D1_SRC "textures/diamond/d1.xpm"
# define D2_SRC "textures/diamond/d2.xpm"
# define D3_SRC "textures/diamond/d3.xpm"
# define D4_SRC "textures/diamond/d4.xpm"
# define D5_SRC "textures/diamond/d5.xpm"
# define D6_SRC "textures/diamond/d6.xpm"
# define D7_SRC "textures/diamond/d7.xpm"
# define D8_SRC "textures/diamond/d8.xpm"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./mlx/mlx.h"
# include <stdio.h>

typedef struct s_map
{
	int		row_len;
	int		row_num;
	int		coins;
	int		enemies;
	char	**map;
}	t_map;

typedef struct s_coins
{
	int	*coins_c;
	int	**coin_pos;
	int	frame;
	void	**coin_imgs;
}	t_coins;

typedef struct s_enemies
{
	int	*enemies_c;
	int	**enemy_pos;
	int	frame;
	void	**enemy_imgs;
}	t_enemies;

typedef struct s_player
{
	int	player_i;
	int	player_j;
	int	frame;
	void	**player_imgs;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*wall_img;
	void		*floor_img;
	void		**exit_img;
	int		move;
	int		*coin;
	char		**m;
	t_map		*map;
	t_coins		*coins;
	t_enemies	*enemies;
	t_player	*player;
}	t_game;

t_map	*map_init(char *src);
void	init_images(t_game *game);
void	map_counter(t_map *rt_map);
void	is_reachable(t_map *rt_map);
void	init_structs(t_game *game);
void	try_exit(t_game *game);
void	to_die(t_game *game);
void	to_move(t_game *game, int i, int j, int key);
void	to_left(t_game *game);
void	to_down(t_game *game);
void	to_right(t_game *game);
void	to_up(t_game *game);
void	get_player_cordinates(t_game *game);
void	render_engine(t_game *game);
void	put_player(t_game *game, int code, int i, int j);
void	put_coins(t_game *game, int code, int i, int j);
void	put_enemy(t_game *game, int code, int i, int j);
char	**ft_split(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_trim(char *rd);
char	*ft_read(int fd);
int		ft_strlen(const char *str);
int		ft_strrchr(char *str, int c);
int		ft_strcmp(char *s1, char *s2);
int		is_01(char c);
int		is_file_exist(char *str);
int		error_code(int code);
int		char_counter(t_map *map, char c);

void	print_game(t_game *game);

#endif
