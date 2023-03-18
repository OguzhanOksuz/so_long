/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:57:37 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 00:55:24 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define W 64
# define H 64

# define BRICK_SRC "textures/envoriment/brick.xpm"
# define PLANK_SRC "textures/envoriment/plank.xpm"
# define PA_SRC "textures/portal/pa.xpm"
# define PDA_SRC "textures/portal/pda.xpm"
# define S0_SRC "textures/steve/s0.xpm"
# define s1_SRC "textures/steve/s1.xpm"
# define s2_SRC "textures/steve/s2.xpm"
# define s3_SRC "textures/steve/s3.xpm"
# define s4_SRCSRC "textures/steve/s4.xpm"
# define s5_SRCSRC "textures/steve/s5.xpm"
# define s6_SRCSRC "textures/steve/s6.xpm"
# define s7_SRCSRC "textures/steve/s7.xpm"
# define s8_SRCSRC "textures/steve/s8.xpm"
# define s9_SRCSRC "textures/steve/s9.xpm"
# define s10_SRC "textures/steve/s10.xpm"
# define s11_SRC "textures/steve/s11.xpm"
# define e0_SRC "textures/dragon/e0.xpm"
# define e1_SRC "textures/dragon/e1.xpm"
# define e2_SRC "textures/dragon/e2.xpm"
# define e3_SRC"textures/dragon/e3.xpm"
# define e4_SRC "textures/dragon/e4.xpm"
# define e5_SRC "textures/dragon/e5.xpm"
# define e6_SRC "textures/dragon/e6.xpm"
# define d0_SRC "textures/diamond/d0.xpm"
# define d1_SRC "textures/diamond/d1.xpm"
# define d2_SRC "textures/diamond/d2.xpm"
# define d3_SRC "textures/diamond/d3.xpm"
# define d4_SRC "textures/diamond/d4.xpm"
# define d5_SRC "textures/diamond/d5.xpm"
# define d6_SRC "textures/diamond/d6.xpm"
# define d7_SRC "textures/diamond/d7.xpm"
# define d8_SRC "textures/diamond/d8.xpm"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
	int		row_len;
	int		row_num;
	int		valid;
	int		player;
	int		coin;
	int		exit;
	int		enemy;
	int		wrong;
	char	*extension;
	char	**map;
}	t_map;

typedef struct s_game
{
	t_map	ren_map;
	void	*mlx;
	void	*window;
	void	**player_imgs;
	void	**diamond_imgs;
	void	**dragon_imgs;
	void	**portal_imgs;
	void	*bricks_img;
	void	*plank_img;
	int		player_x;
	int		player_y;
}	t_game;

t_map	*map_init(char *src);
char	**ft_split(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_trim(char *rd);
char	*ft_read(int fd);
int		ft_strlen(const char *str);
int		ft_strrchr(char *str, int c);
int		ft_strcmp(char *s1, char *s2);
int		is_01(char c);
int		is_reachable(t_map *rt_map);
int		is_file_exist(char *str);
int		error_code(int code);

#endif
