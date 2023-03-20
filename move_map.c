/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:13:48 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/20 15:43:18 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_count(t_game *game, int key)
{
	if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		write(1, "Move = ", 7);
		ft_putnbr(game->move);
		write(1, "\n", 1);
	}
}

void	try_exit(t_game *game)
{
	if (*game->coin == 0)
	{
		game->move++;
		move_count(game, 0);
		exit(1);
	}
}

void	to_collect(t_coins *c, int i, int j)
{
	int	num;
	int	*tmp;

	num = 0;
	while (num < *c->coins_c)
	{
		if (c->coin_pos[num][0] == i && c->coin_pos[num][1] == j)
		{
			tmp = c->coin_pos[num];
			c->coin_pos[num] = c->coin_pos[*c->coins_c - 1];
			c->coin_pos[*c->coins_c - 1] = tmp;
		}
		num++;
	}
	*c->coins_c -= 1;
}

void	to_move(t_game *game, int i, int j, int key)
{
	if (key == 0)
	{
		game->map->map[i][j] = '0';
		game->map->map[i][j - 1] = 'P';
		*game->player_j -= 1;
	}
	if (key == 1)
	{
		game->map->map[i][j] = '0';
		game->map->map[i + 1][j] = 'P';
		*game->player_i += 1;
	}
	if (key == 2)
	{
		game->map->map[i][j] = '0';
		game->map->map[i][j + 1] = 'P';
		*game->player_j += 1;
	}
	if (key == 13)
	{
		game->map->map[i][j] = '0';
		game->map->map[i - 1][j] = 'P';
		*game->player_i -= 1;
	}
	move_count(game, key);
}
