/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:55:05 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 11:08:31 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	coin_count(t_map *rt_map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (rt_map->map[i])
	{
		j = 0;
		while (rt_map->map[i][j])
		{
			if (rt_map->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	rt_map->coin = count;
}

void	exit_count(t_map *rt_map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (rt_map->map[i])
	{
		j = 0;
		while (rt_map->map[i][j])
		{
			if (rt_map->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	rt_map->exit = count;
}

void	map_counter(t_map *rt_map)
{
	rt_map->player = player_count(rt_map);
	exit_count(rt_map);
	coin_count(rt_map);
}

void	get_player_cordinates(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->ren_map->map[i])
	{
		j = 0;
		while (game->ren_map->map[i][j])
		{
			if (game->ren_map->map[i][j] == 'P')
			{
				game->player_i = i;
				game->player_j = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
