/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:21:30 by ooksuz            #+#    #+#             */
/*   Updated: 2023/04/10 18:27:34 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(void **arr, int c)
{
	int	i;

	i = 0;
	while (arr[i] && i < c)
		free(arr[i++]);
	free(arr);
}

void	my_free(t_game *game)
{
	free_arr(game->map->map, gama->map->row_num);
	free_arr(game->coins->coin_pos, gama->coins->coins_c);
	free(game->map);
}
