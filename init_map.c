/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:03:46 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/17 00:59:57 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	read_map(t_map *rt_map, int fd)
{
	int		i;
	char	*line;

	i = 1;
	line = get_next_line(fd);
	rt_map->map[0] = line;
	rt_map->column = ft_strlen(line);
	while (line)
	{
		rt_map->map[i++] = line;
		if (rt_map->column != ft_strlen(line))
			rt_map->column = -1;
		line = get_next_line(fd);
	}
	rt_map->row = i;
}

t_map	*malloc_t_map(void)
{
	t_map	*rt_map;

	rt_map = (t_map *)malloc(sizeof(t_map));
	return (rt_map);
}

t_map	*map_init(char *src)
{
	t_map	*rt_map;
	int		fd;

	rt_map = malloc_t_map();
	fd = open(src, O_RDONLY);
	if (!rt_map || fd < 0)
		return (NULL);
	rt_map->extension = src + ft_strrchr(src, '.') + 1;
//	read_map(rt_map, fd);
	close(fd);
	return (rt_map);
}
int	main(int ac, char **av)
{
	t_map *ren_map = map_init(av[1]);
	printf("Format = %s\n", ren_map->extension);
	(void) ac;
	(void) ren_map;
}
