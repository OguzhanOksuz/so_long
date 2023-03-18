/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 02:13:40 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 01:33:46 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_images(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_code(-500);
	game->window = mlx_new_window(game->mlx, (W * game->ren_map->row_len),
			(H * game->ren_map->row_num), "So_long");
}
