/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 02:13:40 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 02:49:42 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_player_imgs(t_game *game, int *r)
{
	game->player_imgs[0] = mlx_xpm_file_to_image(game->mlx, S0_SRC, r, r);
	game->player_imgs[1] = mlx_xpm_file_to_image(game->mlx, S1_SRC, r, r);
	game->player_imgs[2] = mlx_xpm_file_to_image(game->mlx, S2_SRC, r, r);
	game->player_imgs[3] = mlx_xpm_file_to_image(game->mlx, S3_SRC, r, r);
	game->player_imgs[4] = mlx_xpm_file_to_image(game->mlx, S4_SRC, r, r);
	game->player_imgs[5] = mlx_xpm_file_to_image(game->mlx, S5_SRC, r, r);
	game->player_imgs[6] = mlx_xpm_file_to_image(game->mlx, S6_SRC, r, r);
	game->player_imgs[7] = mlx_xpm_file_to_image(game->mlx, S7_SRC, r, r);
	game->player_imgs[8] = mlx_xpm_file_to_image(game->mlx, S8_SRC, r, r);
	game->player_imgs[9] = mlx_xpm_file_to_image(game->mlx, S9_SRC, r, r);
	game->player_imgs[10] = mlx_xpm_file_to_image(game->mlx, S10_SRC, r, r);
	game->player_imgs[11] = mlx_xpm_file_to_image(game->mlx, S10_SRC, r, r);
}

void	init_images(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_code(-500);
	game->res = 64;
	game->window = mlx_new_window(game->mlx, (W * game->ren_map->row_len),
			(H * game->ren_map->row_num), "So_long");
	game->player_imgs = (void **)malloc(sizeof(void *) * 12);
	game->diamond_imgs = (void **)malloc(sizeof(void *) * 9);
	game->dragon_imgs = (void **)malloc(sizeof(void *) * 7);
	if (!game->player_imgs || !game->diamond_imgs || !game->dragon_imgs)
		error_code(-500);
	init_player_imgs(game, &game->res);
}
