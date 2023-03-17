/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:03:46 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/17 17:28:26 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

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
	(void) ac;
	(void) ren_map;
}
