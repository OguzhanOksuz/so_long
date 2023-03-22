/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 03:21:26 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/23 01:42:06 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_cordinate(t_game *game, int i, int j)
{
	draw_floor(game, i, j);
	if (game->map->map[i][j] == '1')
		draw_wall(game, i, j);
	if (game->map->map[i][j] == 'E')
		draw_exit(game, i, j);
	if (game->map->map[i][j] == 'P')
		draw_player(game, i, j);
	if (game->map->map[i][j] == 'C')
		draw_coin(game, i, j);
}

void	render_move(t_game *game, int code)
{
	render_cordinate(game, *game->player_i, *game->player_j);
	if (code == 0)
		render_cordinate(game, *game->player_i, *game->player_j + 1);
	if (code == 1)
		render_cordinate(game, *game->player_i - 1, *game->player_j);
	if (code == 2)
		render_cordinate(game, *game->player_i, *game->player_j - 1);
	if (code == 13)
		render_cordinate(game, *game->player_i + 1, *game->player_j);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			render_cordinate(game, i, j);
		}
	}
}
