/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:08:25 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 15:35:03 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_map(t_map *map)
{
	printf("row_len = %d\t", map->row_len);
	printf("row_num = %d\n", map->row_num);
	printf("valid = %d\n", map->valid);
	printf("coins = %d\n", map->coins);
	printf("enemies = %d\n", map->enemies);
	for (int i = 0; i < map->row_num; i++)
		printf("%s\n", map->map[i]);
}
