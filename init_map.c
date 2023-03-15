/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:03:46 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/14 22:44:38 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>


t_map	map_init(char *src)
{
//	char	*line;
	t_map	rt_map;
//	int		i;

//	i = 0;
//	line = get_next_line(av[1]);
	rt_map.extension = src + ft_strrchr(src, '.') + 1;
	return (rt_map);
}

int	main(int ac, char **av)
{
	t_map ren_map = map_init(av[1]);
	printf("Freg is the name = %s", ren_map.extension);
	(void) ac;
}
