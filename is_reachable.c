/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reachable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:13:20 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/18 00:14:48 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fill_reachable(t_map *rt_map, int i, int j)
{
	if ((i - 1 > 0) && (rt_map->map[i - 1][j] == '0'
		|| rt_map->map[i - 1][j] == 'C' || rt_map->map[i - 1][j] == 'E'))
		rt_map->map[i - 1][j] = 'P';
	if ((i + 1 < rt_map->row_num) && (rt_map->map[i + 1][j] == '0'
		|| rt_map->map[i + 1][j] == 'C' || rt_map->map[i + 1][j] == 'E'))
		rt_map->map[i + 1][j] = 'P';
	if ((j - 1 > 0) && (rt_map->map[i][j - 1] == '0'
		|| rt_map->map[i][j - 1] == 'C' || rt_map->map[i][j - 1] == 'E'))
		rt_map->map[i][j - 1] = 'P';
	if ((j + 1 < rt_map->row_len) && (rt_map->map[i][j + 1] == '0'
		|| rt_map->map[i][j + 1] == 'C' || rt_map->map[i][j + 1] == 'E'))
		rt_map->map[i][j + 1] = 'P';
}

int	player_count(t_map *rt_map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (rt_map->map[i])
	{
		j = 0;
		while (rt_map->map[i][j])
		{
			if (rt_map->map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	is_reached_everywhere(t_map *rt_map)
{
	int	i;
	int	j;

	i = 0;
	while (rt_map->map[i])
	{
		j = 0;
		while (rt_map->map[i][j])
		{
			if (rt_map->map[i][j] == 'E'
				|| rt_map->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	re_map_reader(t_map *rt_map)
{
	int	i;
	
	i = 0;
	while (rt_map->map[i])
	{
		free(rt_map->map[i]);
		i++;
	}
	free(rt_map->map[i]);
}

int	is_reachable(t_map *rt_map)
{
	int	i;
	int	j;
	int	tmp;

	while (1)
	{
		tmp = player_count(rt_map);
		i = 0;
		while (rt_map->map[i])
		{
			j = 0;
			while (rt_map->map[i][j])
			{
				if (rt_map->map[i][j] == 'P')
					fill_reachable(rt_map, i, j);
				j++;
			}
			i++;
		}
		if (tmp == player_count(rt_map))
			break ;
	}
	re_map_reader(rt_map);
	return (is_reached_everywhere(rt_map));
}
