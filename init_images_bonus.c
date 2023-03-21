/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 02:13:40 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/21 21:08:58 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	init_player_imgs(t_player *p, int *r, void *mlx)
{
	p->player_imgs[0] = mlx_xpm_file_to_image(mlx, S0_SRC, r, r);
	p->player_imgs[1] = mlx_xpm_file_to_image(mlx, S1_SRC, r, r);
	p->player_imgs[2] = mlx_xpm_file_to_image(mlx, S2_SRC, r, r);
	p->player_imgs[3] = mlx_xpm_file_to_image(mlx, S3_SRC, r, r);
	p->player_imgs[4] = mlx_xpm_file_to_image(mlx, S4_SRC, r, r);
	p->player_imgs[5] = mlx_xpm_file_to_image(mlx, S5_SRC, r, r);
	p->player_imgs[6] = mlx_xpm_file_to_image(mlx, S6_SRC, r, r);
	p->player_imgs[7] = mlx_xpm_file_to_image(mlx, S7_SRC, r, r);
	p->player_imgs[8] = mlx_xpm_file_to_image(mlx, S8_SRC, r, r);
	p->player_imgs[9] = mlx_xpm_file_to_image(mlx, S9_SRC, r, r);
	p->player_imgs[10] = mlx_xpm_file_to_image(mlx, S10_SRC, r, r);
	p->player_imgs[11] = mlx_xpm_file_to_image(mlx, S10_SRC, r, r);
	p->frame = 0;
}

void	init_coin_imgs(t_coins *c, int *r, void *mlx)
{
	c->coin_imgs[0] = mlx_xpm_file_to_image(mlx, D0_SRC, r, r);
	c->coin_imgs[1] = mlx_xpm_file_to_image(mlx, D1_SRC, r, r);
	c->coin_imgs[2] = mlx_xpm_file_to_image(mlx, D2_SRC, r, r);
	c->coin_imgs[3] = mlx_xpm_file_to_image(mlx, D3_SRC, r, r);
	c->coin_imgs[4] = mlx_xpm_file_to_image(mlx, D4_SRC, r, r);
	c->coin_imgs[5] = mlx_xpm_file_to_image(mlx, D5_SRC, r, r);
	c->coin_imgs[6] = mlx_xpm_file_to_image(mlx, D6_SRC, r, r);
	c->coin_imgs[7] = mlx_xpm_file_to_image(mlx, D7_SRC, r, r);
	c->coin_imgs[8] = mlx_xpm_file_to_image(mlx, D8_SRC, r, r);
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
}

void	init_static_imgs(t_game *game, int *r, void *mlx)
{
	game->exit_imgs[0] = mlx_xpm_file_to_image(mlx, PDA_SRC, r, r);
	game->exit_imgs[1] = mlx_xpm_file_to_image(mlx, PA_SRC, r, r);
	game->wall_img = mlx_xpm_file_to_image(mlx, BRICK_SRC, r, r);
	game->floor_img = mlx_xpm_file_to_image(mlx, PLANK_SRC, r, r);
}

void	init_images(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_code(-500);
	game->window = mlx_new_window(game->mlx, (RES * game->map->row_len),
			(RES * game->map->row_num), "So_long");
	if (!game->window)
		error_code(-500);
	game->player->player_imgs = (void **)malloc(sizeof(void *) * 12);
	game->coins->coin_imgs = (void **)malloc(sizeof(void *) * 9);
	game->enemies->enemy_imgs = (void **)malloc(sizeof(void *) * 7);
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
