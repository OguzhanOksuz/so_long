/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:08:25 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 19:57:56 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_coins(t_coins *con)
{
	printf("\n-----COINS STATS---\n");
	printf("coins[%p] = %d\n", con->coins_c, *con->coins_c);
	for (int i = 0; i < *con->coins_c; i++)
		printf("Coin[%d] = [%d][%d]\n", i, con->coin_pos[i][0], con->coin_pos[i][1]);

}

void	print_enemies(t_enemies *en)
{
	printf("\n-----enemies stats---\n");
	printf("enemies[%p] = %d\n", en->enemies_c, *en->enemies_c);
	for (int i = 0; i < *en->enemies_c; i++)
		printf("Coin[%d] = [%d][%d]\n", i, en->enemy_pos[i][0], en->enemy_pos[i][1]);
}

void	print_player(t_player *player)
{	
	printf("\n-----enemies stats---\n");
	printf("player[%d][%d]\n", player->player_i, player->player_j);

}

void	print_map(t_map *map)
{
	printf("row_len = %d\t", map->row_len);
	printf("row_num = %d\n", map->row_num);
	printf("coins[%p] = %d\n", &map->coins, map->coins);
	printf("enemies = %d\n", map->enemies);
	for (int i = 0; i < map->row_num; i++)
		printf("%s\n", map->map[i]);
}

void	print_game(t_game *game)
{
	printf("\033[2J");
    	printf("\033[H"); 
	print_map(game->map);
	print_player(game->player);
	print_coins(game->coins);
	print_enemies(game->enemies);
}
