/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:03:46 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/18 00:20:55 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	read_map(t_map *rd_map)
{
	int	i;
	int	j;

	i = 0;
	while (rd_map->map[i])
	{
		j = 0;
		while (rd_map->map[i][j])
		{
			if (rd_map->map[i][j] == 'P')
				rd_map->player++;
			else if (rd_map->map[i][j] == 'C')
				rd_map->coin++;
			else if (rd_map->map[i][j] == 'E')
				rd_map->exit++;
			else if (rd_map->map[i][j] == 'X')
				rd_map->enemy++;
			else if (is_01(rd_map->map[i][j]) == 0)
				rd_map->wrong++;
			j++;
		}
		i++;
	}
}

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
	if (ft_strcmp(rt_map->extension, "ber") == 0)
		return (-1);
	if (rt_map->row_len == -1)
		return (-2);
	if (rt_map->wrong != 0)
		return (-3);
	if (rt_map->player != 1)
		return (-4);
	if (rt_map->exit != 1)
		return (-5);
	if (rt_map->coin == 0)
		return (-6);
	if (is_wall_correct(rt_map) == 0)
		return (-7);
	if (is_reachable(rt_map) == 0)
		return (-8);
	return (1);
}


void	re_map_reader(t_map *rt_map, char *src)
{
	int	i;
	int	fd;
	
	i = 0;
	while (rt_map->map[i])
	{
		free(rt_map->map[i]);
		i++;
	}
	free(rt_map->map[i]);
	free(rt_map->map);
	fd = open(src, O_RDONLY);
	rt_map->map = ft_split(ft_read(fd), '\n');
	close(fd);
}

t_map	*map_init(char *src)
{
	t_map	*rt_map;
	int		fd;
	int		i;

	rt_map = (t_map *)malloc(sizeof(t_map));
	fd = open(src, O_RDONLY);
	if (!rt_map || fd < 0)
		return (NULL);
	rt_map->extension = src + ft_strrchr(src, '.') + 1;
	rt_map->map = ft_split(ft_read(fd), '\n');
	close(fd);
	i = 0;
	rt_map->row_len = ft_strlen(rt_map->map[0]);
	while (rt_map->map[i])
	{
		if (ft_strlen(rt_map->map[i]) != rt_map->row_len)
			rt_map->row_len = -1;
		i++;
	}
	rt_map->row_num = i;
	read_map(rt_map);
	rt_map->valid = is_map_valid(rt_map);
	re_map_reader(rt_map, src);;
	return (rt_map);
}

int	main(int ac, char **av)
{
	t_map *ren_map = map_init(av[1]);
	int i = ren_map->row_num;

	printf("Format = %s\n", ren_map->extension);
	printf("row_len = %d\n", ren_map->row_len);
	printf("row_num = %d\n", ren_map->row_num);
	while (i--)
		printf("%s\n", ren_map->map[i]);
	printf("valid = %d\n", ren_map->valid);
	printf("wrong = %d\n", ren_map->wrong);
	printf("player = %d\n", ren_map->player);
	printf("coin = %d\n", ren_map->coin);
	printf("exit = %d\n", ren_map->exit);
	printf("enemy = %d\n", ren_map->enemy);
	system("leeks so_long");
	(void) ac;
	(void) ren_map;
}
