/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:17:12 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 17:55:28 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	**create_matris(int i, int j)
{
	int **rt;

	rt = (int **)malloc(sizeof(int *) * i);
	if (!rt)
		error_code(-500);
	while (--i)
	{
		rt[i] = (int *)malloc(sizeof(int) * j);
		if (!rt[i])
			error_code(-500);
	}
	return (rt);
}

int	**get_poses(t_map *map, char c)
{
	int	i;
	int	j;
	int	**rt;
	int	count;

	count = 0;
	rt = create_matris(char_counter(map, c), 2);
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == c)
			{
				rt[count][0] = i;
				rt[count][1] = j;
				count++;
			}	
		}
	}
	return (rt);
}	

void	init_structs(t_game *game)
{
	t_coins		coins;
	t_enemies	enemies;
	t_player	player;
	coins.coins_c = &game->map->coins;

	game->coins = &coins;
	game->enemies = &enemies;
	game->player = &player;
}
