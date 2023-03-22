/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics_engine_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 04:28:11 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/23 01:47:59 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	to_left(t_game *game)
{
	int	i;
	int	j;

	i = *game->player_i;
	j = *game->player_j;
	if (j > 0)
	{
		if (game->map->map[i][j - 1] == 'E')
			try_exit(game);
		if (game->map->map[i][j - 1] != '1')
			game->move++;
		if (game->map->map[i][j - 1] == 'X')
			error_code(-101010);
		if (game->map->map[i][j - 1] == '0')
			to_move(game, i, j, 0);
		if (game->map->map[i][j - 1] == 'C')
		{
			to_collect(game->coins, i, j - 1);
			to_move(game, i, j, 0);
			render_cordinate(game, game->exit_i, game->exit_j);
		}
	}
}

void	to_down(t_game *game)
{
	int	i;
	int	j;

	i = *game->player_i;
	j = *game->player_j;
	if (i < game->map->row_num)
	{
		if (game->map->map[i + 1][j] == 'E')
			try_exit(game);
		if (game->map->map[i + 1][j] != '1')
			game->move++;
		if (game->map->map[i + 1][j] == 'X')
			error_code(-101010);
		if (game->map->map[i + 1][j] == '0')
			to_move(game, i, j, 1);
		if (game->map->map[i + 1][j] == 'C')
		{
			to_collect(game->coins, i + 1, j);
			to_move(game, i, j, 1);
			render_cordinate(game, game->exit_i, game->exit_j);
		}
	}
}

void	to_right(t_game *game)
{
	int	i;
	int	j;

	i = *game->player_i;
	j = *game->player_j;
	if (j < game->map->row_len)
	{
		if (game->map->map[i][j + 1] == 'E')
			try_exit(game);
		if (game->map->map[i][j + 1] != '1')
			game->move++;
		if (game->map->map[i][j + 1] == 'X')
			error_code(-101010);
		if (game->map->map[i][j + 1] == '0')
			to_move(game, i, j, 2);
		if (game->map->map[i][j + 1] == 'C')
		{
			to_collect(game->coins, i, j  + 1);
			to_move(game, i, j, 2);
			render_cordinate(game, game->exit_i, game->exit_j);
		}
	}
}

void	to_up(t_game *game)
{
	int	i;
	int	j;

	i = *game->player_i;
	j = *game->player_j;
	if (i > 0)
	{
		if (game->map->map[i - 1][j] == 'E')
			try_exit(game);
		else if (game->map->map[i - 1][j] != '1')
			game->move++;
		if (game->map->map[i - 1][j] == 'X')
			error_code(-101010);
		if (game->map->map[i - 1][j] == '0')
			to_move(game, i, j, 13);
		if (game->map->map[i - 1][j] == 'C')
		{
			to_collect(game->coins, i - 1, j);
			to_move(game, i, j, 13);
			render_cordinate(game, game->exit_i, game->exit_j);
		}
	}
}
