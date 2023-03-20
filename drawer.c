/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:14:35 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/20 15:46:31 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_exit(t_game *g, int i, int j)
{
	if (*g->coin != 0)
		mlx_put_image_to_window(g->mlx, g->window, g->exit_imgs[1],
			j * RES, i * RES);
	else
		mlx_put_image_to_window(g->mlx, g->window, g->exit_imgs[0],
			j * RES, i * RES);
}

void	draw_floor(t_game *g, int i, int j)
{
	mlx_put_image_to_window(g->mlx, g->window,
		g->floor_img, j * RES, i * RES);
}

void	draw_wall(t_game *g, int i, int j)
{
	mlx_put_image_to_window(g->mlx, g->window,
		g->wall_img, j * RES, i * RES);
}

void	draw_coin(t_game *g, int i, int j)
{
	mlx_put_image_to_window(g->mlx, g->window,
		g->coins->coin_img, j * RES, i * RES);
}

void	draw_player(t_game *g, int i, int j)
{
	mlx_put_image_to_window(g->mlx, g->window,
		g->player->player_img, j * RES, i * RES);
}
