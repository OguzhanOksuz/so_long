/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 02:13:40 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/23 00:32:08 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	init_player_imgs(t_player *p, int *r, void *mlx)
{
	p->player_imgs[0] = mlx_xpm_file_to_image(mlx, P0_SRC, r, r);
	p->player_imgs[1] = mlx_xpm_file_to_image(mlx, P1_SRC, r, r);
	p->player_imgs[2] = mlx_xpm_file_to_image(mlx, P2_SRC, r, r);
	p->player_imgs[3] = mlx_xpm_file_to_image(mlx, P3_SRC, r, r);
	p->player_imgs[4] = mlx_xpm_file_to_image(mlx, P4_SRC, r, r);
	p->player_imgs[5] = mlx_xpm_file_to_image(mlx, P5_SRC, r, r);
	p->player_imgs[6] = mlx_xpm_file_to_image(mlx, P6_SRC, r, r);
	p->player_imgs[7] = mlx_xpm_file_to_image(mlx, P7_SRC, r, r);
	p->player_imgs[8] = mlx_xpm_file_to_image(mlx, P8_SRC, r, r);
	p->player_imgs[9] = mlx_xpm_file_to_image(mlx, P9_SRC, r, r);
	p->player_imgs[10] = mlx_xpm_file_to_image(mlx, P10_SRC, r, r);
	p->player_imgs[11] = mlx_xpm_file_to_image(mlx, P11_SRC, r, r);
	p->player_imgs[12] = mlx_xpm_file_to_image(mlx, P12_SRC, r, r);
	p->player_imgs[13] = mlx_xpm_file_to_image(mlx, P13_SRC, r, r);
	p->player_imgs[14] = mlx_xpm_file_to_image(mlx, P14_SRC, r, r);
	p->player_imgs[15] = mlx_xpm_file_to_image(mlx, P15_SRC, r, r);
	p->frame = 0;
}

void	init_coin_imgs(t_coins *c, int *r, void *mlx)
{
	c->coin_imgs[0] = mlx_xpm_file_to_image(mlx, C0_SRC, r, r);
	c->coin_imgs[1] = mlx_xpm_file_to_image(mlx, C1_SRC, r, r);
	c->coin_imgs[2] = mlx_xpm_file_to_image(mlx, C2_SRC, r, r);
	c->coin_imgs[3] = mlx_xpm_file_to_image(mlx, C3_SRC, r, r);
	c->coin_imgs[4] = mlx_xpm_file_to_image(mlx, C4_SRC, r, r);
	c->coin_imgs[5] = mlx_xpm_file_to_image(mlx, C5_SRC, r, r);
	c->coin_imgs[6] = mlx_xpm_file_to_image(mlx, C6_SRC, r, r);
	c->coin_imgs[7] = mlx_xpm_file_to_image(mlx, C7_SRC, r, r);
	c->coin_imgs[8] = mlx_xpm_file_to_image(mlx, C8_SRC, r, r);
	c->coin_imgs[9] = mlx_xpm_file_to_image(mlx, C9_SRC, r, r);
	c->coin_imgs[10] = mlx_xpm_file_to_image(mlx, C10_SRC, r, r);
	c->coin_imgs[11] = mlx_xpm_file_to_image(mlx, C11_SRC, r, r);
	c->frame = 0;
}

void	init_enemy_imgs(t_enemies *e, int *r, void *mlx)
{
	e->enemy_imgs[0] = mlx_xpm_file_to_image(mlx, E0_SRC, r, r);
	e->enemy_imgs[1] = mlx_xpm_file_to_image(mlx, E1_SRC, r, r);
	e->enemy_imgs[2] = mlx_xpm_file_to_image(mlx, E2_SRC, r, r);
	e->enemy_imgs[3] = mlx_xpm_file_to_image(mlx, E3_SRC, r, r);
	e->enemy_imgs[4] = mlx_xpm_file_to_image(mlx, E4_SRC, r, r);
	e->enemy_imgs[5] = mlx_xpm_file_to_image(mlx, E5_SRC, r, r);
	e->enemy_imgs[6] = mlx_xpm_file_to_image(mlx, E6_SRC, r, r);
	e->enemy_imgs[7] = mlx_xpm_file_to_image(mlx, E7_SRC, r, r);
	e->enemy_imgs[8] = mlx_xpm_file_to_image(mlx, E8_SRC, r, r);
	e->enemy_imgs[9] = mlx_xpm_file_to_image(mlx, E9_SRC, r, r);
	e->enemy_imgs[10] = mlx_xpm_file_to_image(mlx, E10_SRC, r, r);
	e->enemy_imgs[11] = mlx_xpm_file_to_image(mlx, E11_SRC, r, r);
	e->enemy_imgs[12] = mlx_xpm_file_to_image(mlx, E12_SRC, r, r);
	e->enemy_imgs[13] = mlx_xpm_file_to_image(mlx, E13_SRC, r, r);
	e->enemy_imgs[14] = mlx_xpm_file_to_image(mlx, E14_SRC, r, r);
	e->enemy_imgs[15] = mlx_xpm_file_to_image(mlx, E15_SRC, r, r);
	e->frame = 0;
}

void	init_static_imgs(t_game *game, int *r, void *mlx)
{
	game->exit_imgs[0] = mlx_xpm_file_to_image(mlx, EDA_SRC, r, r);
	game->exit_imgs[1] = mlx_xpm_file_to_image(mlx, EA_SRC, r, r);
	game->wall_img = mlx_xpm_file_to_image(mlx, W_SRC, r, r);
	game->floor_img = mlx_xpm_file_to_image(mlx, F_SRC, r, r);
}

void	init_images(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_code(-500);
	game->window = mlx_new_window(game->mlx, (RES * game->map->row_len),
			(RES * game->map->row_num), "So_long_bonus");
	if (!game->window)
		error_code(-500);
	game->player->player_imgs = (void **)malloc(sizeof(void *) * 16);
	game->coins->coin_imgs = (void **)malloc(sizeof(void *) * 12);
	game->enemies->enemy_imgs = (void **)malloc(sizeof(void *) * 16);
	game->exit_imgs = (void **)malloc(sizeof(void *) * 2);
	if (!game->player->player_imgs || !game->coins->coin_imgs
		|| !game->enemies->enemy_imgs || !game->exit_imgs)
		error_code(-500);
	game->res = 64;
	init_player_imgs(game->player, &game->res, game->mlx);
	init_coin_imgs(game->coins, &game->res, game->mlx);
	init_enemy_imgs(game->enemies, &game->res, game->mlx);
	init_static_imgs(game, &game->res, game->mlx);
}
