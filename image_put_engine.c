/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_put_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 04:09:15 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 04:18:18 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_player(t_game *game, int code, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->window, game->player_imgs[code],
				j * game->res + (4 * code), i * game->res + (4 * code));
}

void	put_coins(t_game *game, int code, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->window, game->coin_imgs[code],
				j * game->res + (4 * code), i * game->res + (4 * code));
}

void	put_enemy(t_game *game, int code, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->window, game->enemy_imgs[code],
				j * game->res + (4 * code), i * game->res + (4 * code));
}
