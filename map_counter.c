/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:55:05 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 15:34:18 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	player_count(t_map *rt_map)
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
			if (rt_map->map[i][j] == 'P')
				count++;
			if (count > 1)
				error_code(-4);
			j++;
		}
		i++;
	}
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
			if (count > 1)
				error_code(-4);
			j++;
		}
		i++;
	}
}

int	char_counter(t_map *map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == c)
				count++;
		}
	}
	return (count);
}

void	map_counter(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (!(map->map[i][j] == '1' || map->map[i][j] == '0' ||
				map->map[i][j] == 'P' ||
				map->map[i][j] == 'E' ||
				map->map[i][j] == 'C' ||
				map->map[i][j] == 'X'))
				error_code(-3);
		}
	}
	player_count(map);
	exit_count(map);
	map->coins = char_counter(map, 'C');
	map->enemies = char_counter(map, 'X');
}
