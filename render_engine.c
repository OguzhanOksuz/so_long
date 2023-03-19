/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 03:21:26 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 03:44:03 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_engine(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->ren_map->map[i])
	{
		j = 0;
		while (game->ren_map->map[i][j])
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->plank_img, j * game->res, i * game->res);
			if (game->ren_map->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window,
					game->brick_img, j * game->res, i * game->res);
			j++;
		}
		i++;
	}
//	draw_player(game);
//	draw_coins(game);
//	draw_enemies(game);
//	draw_exit(game);
}
