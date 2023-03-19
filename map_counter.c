/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:55:05 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 16:47:50 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	if (char_counter(map, 'P') != 1)
		error_code(-4);
	if (char_counter(map, 'E') != 1)
		error_code(-4);
	map->coins = char_counter(map, 'C');
	if (map->coins == 0)
		error_code(-4);
	map->enemies = char_counter(map, 'X');
}
