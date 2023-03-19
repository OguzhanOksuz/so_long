/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:13:48 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 12:38:28 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	try_exit(t_game *game)
{
	if (game->ren_map->coin == 0)
	{
		game->move++;
		write(1, "YOU WON\n", 8);
		exit(1);
	}
}

void	to_die(t_game *game)
{
	game->move++;
	error_code(-101010);
}

void	to_move(t_game *game, int i, int j, int key)
{
	if (key == 0)
	{
		game->ren_map->map[i][j] = '0';
		game->ren_map->map[i][j - 1] = 'P';
		game->player_j--;
	}
	if (key == 1)
	{
		game->ren_map->map[i][j] = '0';
		game->ren_map->map[i + 1][j] = 'P';
		game->player_i++;
	}
	if (key == 2)
	{
		game->ren_map->map[i][j] = '0';
		game->ren_map->map[i][j + 1] = 'P';
		game->player_j++;
	}
	if (key == 13)
	{
		game->ren_map->map[i][j] = '0';
		game->ren_map->map[i - 1][j] = 'P';
		game->player_i--;
	}
}
