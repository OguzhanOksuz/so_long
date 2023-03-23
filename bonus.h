/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:57:37 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/24 00:45:23 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# define RES 64

# define W_SRC "textures/W.xpm"
# define F_SRC "textures/F.xpm"
# define EA_SRC "textures/EA.xpm"
# define EDA_SRC "textures/EDA.xpm"
# define P0_SRC "textures/P0.xpm"
# define P1_SRC "textures/P1.xpm"
# define P2_SRC "textures/P2.xpm"
# define P3_SRC "textures/P3.xpm"
# define P4_SRC "textures/P4.xpm"
# define P5_SRC "textures/P5.xpm"
# define P6_SRC "textures/P6.xpm"
# define P7_SRC "textures/P7.xpm"
# define P8_SRC "textures/P8.xpm"
# define P9_SRC "textures/P9.xpm"
# define P10_SRC "textures/P10.xpm"
# define P11_SRC "textures/P11.xpm"
# define P12_SRC "textures/P12.xpm"
# define P13_SRC "textures/P13.xpm"
# define P14_SRC "textures/P14.xpm"
# define P15_SRC "textures/P15.xpm"
# define C0_SRC "textures/C0.xpm"
# define C1_SRC "textures/C1.xpm"
# define C2_SRC "textures/C2.xpm"
# define C3_SRC "textures/C3.xpm"
# define C4_SRC "textures/C4.xpm"
# define C5_SRC "textures/C5.xpm"
# define C6_SRC "textures/C6.xpm"
# define C7_SRC "textures/C7.xpm"
# define C8_SRC "textures/C8.xpm"
# define C9_SRC "textures/C9.xpm"
# define C10_SRC "textures/C10.xpm"
# define C11_SRC "textures/C11.xpm"
# define E0_SRC "textures/E0.xpm"
# define E1_SRC "textures/E1.xpm"
# define E2_SRC "textures/E2.xpm"
# define E3_SRC "textures/E3.xpm"
# define E4_SRC "textures/E4.xpm"
# define E5_SRC "textures/E5.xpm"
# define E6_SRC "textures/E6.xpm"
# define E7_SRC "textures/E7.xpm"
# define E8_SRC "textures/E8.xpm"
# define E9_SRC "textures/E9.xpm"
# define E10_SRC "textures/E10.xpm"
# define E11_SRC "textures/E11.xpm"
# define E12_SRC "textures/E12.xpm"
# define E13_SRC "textures/E13.xpm"
# define E14_SRC "textures/E14.xpm"
# define E15_SRC "textures/E15.xpm"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./mlx/mlx.h"
# include <sys/time.h>

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
	int		*coins_c;
	int		**coin_pos;
	int		frame;
	void	**coin_imgs;
}	t_coins;

typedef struct s_enemies
{
	int		*enemies_c;
	int		**enemy_pos;
	int		**way;
	int		frame;
	void	**enemy_imgs;
}	t_enemies;

typedef struct s_player
{
	int		player_i;
	int		player_j;
	int		frame;
	void	**player_imgs;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*wall_img;
	void		*floor_img;
	void		**exit_imgs;
	long long	time;
	int			move;
	int			res;
	int			*coin;
	int			*player_i;
	int			*player_j;
	int			exit_i;
	int			exit_j;
	int			color;
	int			delta;
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
void	to_collect(t_coins *coins, int i, int j);
void	get_player_cordinates(t_game *game);
void	render_engine(t_game *game);
void	put_player(t_game *game, int code, int i, int j);
void	put_coins(t_game *game, int code, int i, int j);
void	put_enemy(t_game *game, int code, int i, int j);
void	draw_exit(t_game *g, int i, int j);
void	draw_floor(t_game *g, int i, int j);
void	draw_wall(t_game *g, int i, int j);
void	draw_player(t_game *g, int i, int j);
void	draw_coin(t_game *g, int i, int j);
void	render_map(t_game *game);
void	render_move(t_game *game, int key);
void	render_cordinate(t_game *game, int i, int j);
void	animation_engine(t_game *game);
void	animate_player(t_game *g, t_player *p);
void	animate_enemies(t_game *g, t_enemies *e);
void	animate_enemy(t_game *g, t_enemies *e, int p);
void	patrol_enemies(t_game *g);
void	to_die(t_game *game);
char	**ft_split(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_trim(char *rd);
char	*ft_read(int fd);
char	*ft_itoa(int num);
int		ft_strlen(const char *str);
int		ft_strrchr(char *str, int c);
int		ft_strcmp(char *s1, char *s2);
int		is_01(char c);
int		is_file_exist(char *str);
int		error_code(int code);
int		char_counter(t_map *map, char c);

#endif
