/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 03:21:26 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 13:36:47 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_cordinate(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->plank_img, j * game->res, i * game->res);
	if (game->ren_map->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->brick_img, j * game->res, i * game->res);
	if (game->ren_map->map[i][j] == 'X')
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemy_imgs[0], j * game->res, i * game->res);
	if (game->ren_map->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->player_imgs[0], j * game->res, i * game->res);
	if (game->ren_map->map[i][j] == 'E' && game->ren_map->coin == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->portal_a_img, j * game->res, i * game->res);
	if (game->ren_map->map[i][j] == 'E' && game->ren_map->coin != 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->portal_d_img, j * game->res, i * game->res);
}

//-*********-****-****

void	draw_exit(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->ren_map->map[i])
	{
		j = 0;
		while (g->ren_map->map[i][j])
		{
			if (g->ren_map->map[i][j] == 'E')
			{
				if (g->ren_map->coin == 0)
					mlx_put_image_to_window(g->mlx,
						g->window, g->portal_a_img,
						j * g->res, i * g->res);
				else
					mlx_put_image_to_window(g->mlx,
						g->window, g->portal_d_img,
						j * g->res, i * g->res);
			}
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game)
{
	static int	code = 0;
	int			i;
	int			j;

	i = 0;
	while (game->ren_map->map[i])
	{
		j = 0;
		while (game->ren_map->map[i][j])
		{
			if (game->ren_map->map[i][j] == 'P')
				put_player(game, code++, i, j);
			j++;
		}
		i++;
	}
	if (code == 12)
		code = 0;
}

void	draw_coins(t_game *game)
{
	static int	code = 0;
	int			i;
	int			j;

	i = 0;
	while (game->ren_map->map[i])
	{
		j = 0;
		while (game->ren_map->map[i][j])
		{
			if (game->ren_map->map[i][j] == 'C')
				put_coins(game, code++, i, j);
			j++;
		}
		i++;
	}
	if (code == 9)
		code = 0;
}

void	draw_enemies(t_game *game)
{
	static int	code = 0;
	int			i;
	int			j;

	i = 0;
	while (game->ren_map->map[i])
	{
		j = 0;
		while (game->ren_map->map[i][j])
		{
			if (game->ren_map->map[i][j] == 'X')
				put_enemy(game, code++, i, j);
			j++;
		}
		i++;
	}
	if (code == 7)
		code = 0;
}

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
			render_cordinate(game, i, j);
			j++;
		}
		i++;
	}
}
