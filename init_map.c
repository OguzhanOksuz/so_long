/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:03:46 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/28 06:24:04 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	line_counter(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

void	is_wall_correct(t_map *rt_map)
{
	int	i;

	i = 0;
	while (rt_map->map[0][i])
		if (rt_map->map[0][i++] != '1')
			error_code(-5);
	i = 0;
	while (rt_map->map[rt_map->row_num - 1][i])
		if (rt_map->map[rt_map->row_num - 1][i++] != '1')
			error_code(-5);
	i = rt_map->row_num - 2;
	while (i > 0)
	{
		if (rt_map->map[i][0] != '1')
			error_code(-5);
		if (rt_map->map[i][rt_map->row_len - 1] != '1')
			error_code(-5);
		i--;
	}
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
	close(fd);
	i = 0;
	if (flag == 1)
	{
		while (rt_map->map[i])
			free(rt_map->map[i++]);
		free(rt_map->map[i++]);
		free(rt_map->map);
	}
	i = 0;
	rt_map->map = ft_split(rd, '\n');
	while (rt_map->map[i])
		i++;
	if (i != line_counter(rd))
		error_code(-2);
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
	is_wall_correct(rt_map);
	is_reachable(rt_map);
	map_reader(rt_map, src, 1);
	return (rt_map);
}
