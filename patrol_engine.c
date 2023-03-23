/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:34:11 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/23 22:45:29 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	check_patrol(t_game *g, t_enemies *e, int p)
{
	if (e->way[p][0] == -1)
	{
		if (g->map->map[e->enemy_pos[p][0]]
			[e->enemy_pos[p][1] - 1] == 'P')
			error_code(-101010);
		else if (g->map->map[e->enemy_pos[p][0]]
			[e->enemy_pos[p][1] - 1] != '0')
			e->way[p][0] = 0;
	}
	else if (e->way[p][0] == 1)
	{
		if (g->map->map[e->enemy_pos[p][0]]
			[e->enemy_pos[p][1] + 1] == 'P')
			error_code(-101010);
		else if (g->map->map[e->enemy_pos[p][0]]
			[e->enemy_pos[p][1] + 1] != '0')
			e->way[p][0] = 0;
	}
}

void	patrol_enemy(t_game *g, t_enemies *e, int p)
{
	if (e->way[p][0] == -1)
	{
		g->map->map[e->enemy_pos[p][0]][e->enemy_pos[p][1]] = '0';
		draw_floor(g, e->enemy_pos[p][0], e->enemy_pos[p][1]);
		e->enemy_pos[p][1] -= 1;
		g->map->map[e->enemy_pos[p][0]][e->enemy_pos[p][1]] = 'X';
	}
	else if (e->way[p][0] == 1)
	{
		g->map->map[e->enemy_pos[p][0]][e->enemy_pos[p][1]] = '0';
		draw_floor(g, e->enemy_pos[p][0], e->enemy_pos[p][1]);
		e->enemy_pos[p][1] += 1;
		g->map->map[e->enemy_pos[p][0]][e->enemy_pos[p][1]] = 'X';
	}
	animate_enemy(g, e, p);
}

void	patrol_enemies(t_game *g)
{
	int	i;
	int	tmpi;
	int	tmpj;

	i = 0;
	while (i < *g->enemies->enemies_c)
	{
		if (g->enemies->way[i][0] == 0)
		{
			tmpi = g->enemies->enemy_pos[i][0];
			tmpj = g->enemies->enemy_pos[i][1];
			if (g->map->map[tmpi][tmpj - 1] == '0')
				g->enemies->way[i][0] = -1;
			else if (g->map->map[tmpi][tmpj + 1] == '0')
				g->enemies->way[i][0] = 1;
		}
		check_patrol(g, g->enemies, i);
		patrol_enemy(g, g->enemies, i);
		i++;
	}
}
