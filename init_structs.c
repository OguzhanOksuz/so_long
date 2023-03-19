/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:17:12 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 19:16:27 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	**create_matris(int i, int j)
{
	int	**rt;
	int	a;

	rt = (int **)malloc(sizeof(int *) * i);
	if (!rt)
		error_code(-500);
	a = 0;
	while (a < i)
	{
		rt[a] = (int *)malloc(sizeof(int) * j);
		if (!rt[a])
			error_code(-500);
		a++;
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

void	player_cordinates(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
			{
				player->player_i = i;
				player->player_j = j;
			}
		}
	}
}

void	init_structs(t_game *game)
{
	t_coins		*coins;
	t_enemies	*enemies;
	t_player	*player;

	coins = (t_coins *)malloc(sizeof(t_coins));
	enemies = (t_enemies *)malloc(sizeof(t_enemies));
	player = (t_player *)malloc(sizeof(t_player));
	if (!coins || !enemies || !player)
		error_code(-500);
	coins->coins_c = &game->map->coins;
	coins->coin_pos = get_poses(game->map, 'C');
	enemies->enemies_c = &game->map->enemies;
	enemies->enemy_pos = get_poses(game->map, 'X');
	player_cordinates(game->map, player);
	game->m = game->map->map;
	game->coins = coins;
	game->enemies = enemies;
	game->player = player;
	game->move = 0;
	game->coin = &game->map->coins;
}
