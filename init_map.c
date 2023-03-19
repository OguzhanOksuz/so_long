/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:03:46 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 15:38:11 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_wall_correct(t_map *rt_map)
{
	int	i;

	i = 0;
	while (rt_map->map[0][i])
		if (rt_map->map[0][i++] != '1')
			return (0);
	i = 0;
	while (rt_map->map[rt_map->row_num - 1][i])
		if (rt_map->map[rt_map->row_num - 1][i++] != '1')
			return (0);
	i = rt_map->row_num - 2;
	while (i > 0)
	{
		if (rt_map->map[i][0] != '1')
			return (0);
		if (rt_map->map[i][rt_map->row_len - 1] != '1')
			return (0);
		i--;
	}
	return (1);
}

int	is_map_valid(t_map *rt_map)
{
	if (is_wall_correct(rt_map) == 0)
		error_code(-5);
	if (is_reachable(rt_map) == 0)
		error_code (-6);
	return (1);
}

void	map_reader(t_map *rt_map, char *src, int flag)
{
	char	*rd;
	int		i;
	int		fd;

	fd = open(src, O_RDONLY);
	if (fd < 0)
		error_code(-404);
	rd = ft_read(fd);
	if (!rd)
		error_code(-500);
	i = 0;
	if (flag == 1)
	{
		while (rt_map->map[i])
			free(rt_map->map[i++]);
		free(rt_map->map[i++]);
		free(rt_map->map);
	}
	rt_map->map = ft_split(rd, '\n');
	free(rd);
}

t_map	*map_init(char *src)
{
	t_map	*rt_map;
	int		i;

	rt_map = (t_map *)malloc(sizeof(t_map));
	if (!rt_map)
		error_code(-500);
	if (ft_strcmp(src + ft_strrchr(src, '.') + 1, "ber") == 0)
		error_code(-1);
	map_reader(rt_map, src, 0);
	i = 0;
	rt_map->row_len = ft_strlen(rt_map->map[0]);
	while (rt_map->map[i])
	{
		if (ft_strlen(rt_map->map[i]) != rt_map->row_len)
			error_code(-2);
		i++;
	}
	rt_map->row_num = i;
	map_counter(rt_map);
	rt_map->valid = is_map_valid(rt_map);
	map_reader(rt_map, src, 1);
	print_map(rt_map);
	return (rt_map);
}
