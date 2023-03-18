/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:55:05 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 02:00:26 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	player_count(t_map *rt_map)
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
			j++;
		}
		i++;
	}
	return (count);
}
