/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:03:46 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/15 00:01:29 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>


t_map	map_init(char *src)
{
	t_map	rt_map;
	int		fd;

	fd = open(src, O_RDONLY);
	if (fd < 0)
		return (NULL);
	rt_map.extension = src + ft_strrchr(src, '.') + 1;
	read_map(&rt_map, fd);
	close(fd);
	return (rt_map);
}

void	read_map(t_map &rt_map, int fd)
{

}

int	main(int ac, char **av)
{
	t_map ren_map = map_init(av[1]);
	printf("Freg is the name = %s", ren_map.extension);
	(void) ac;
}
