/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 00:04:29 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/23 01:10:31 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include <stdio.h>

void	animate_player(t_game *g, t_player *p)
{
	draw_floor(g, p->player_i, p->player_j);
	mlx_put_image_to_window(g->mlx, g->window, p->player_imgs[p->frame++],
		p->player_j * RES, p->player_i * RES);
	if (p->frame == 16)
		p->frame = 0;
}

void	animate_coins(t_game *g, t_coins *c)
{
	int	i;

	i = 0;
	while (i < *c->coins_c)
	{
		draw_floor(g, c->coin_pos[i][0], c->coin_pos[i][1]);
		mlx_put_image_to_window(g->mlx, g->window,
				c->coin_imgs[c->frame], c->coin_pos[i][1] * RES,
			c->coin_pos[i][0] * RES);
		i++;
	}
	c->frame++;
	if (c->frame == 12)
		c->frame = 0;
}

void	animate_enemy(t_game *g, t_enemies *e, int p)
{
	draw_floor(g, e->enemy_pos[p][0], e->enemy_pos[p][1]);
	mlx_put_image_to_window(g->mlx, g->window,
		e->enemy_imgs[e->frame], e->enemy_pos[p][1] * RES,
		e->enemy_pos[p][0] * RES);
}

void	animate_enemies(t_game *g, t_enemies *e)
{
	int	i;

	i = 0;
	while (i < *e->enemies_c)
	{
		draw_floor(g, e->enemy_pos[i][0], e->enemy_pos[i][1]);
		mlx_put_image_to_window(g->mlx, g->window,
			e->enemy_imgs[e->frame], e->enemy_pos[i][1] * RES,
			e->enemy_pos[i][0] * RES);
		i++;
	}
	e->frame++;
	if (e->frame == 16)
		e->frame = 0;
}

void	animation_engine(t_game *game)
{
	animate_player(game, game->player);
	animate_coins(game, game->coins);
	animate_enemies(game, game->enemies);
}
