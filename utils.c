/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:56:15 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/17 22:31:03 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	fill_reachable(t_map *rt_map, int i, int j)
{
	int	flag;

	flag = 0;
	if ((i - 1 > 0) && (rt_map->map[i - 1][j] == '0'
		|| rt_map->map[i - 1][j] == 'C' || rt_map->map[i - 1][j] == 'E'))
	{
		rt_map->map[i - 1][j] = 'P';
		flag = 1;
	}
	if ((i + 1 < rt_map->row_len - 1) && (rt_map->map[i + 1][j] == '0'
		|| rt_map->map[i + 1][j] == 'C' || rt_map->map[i + 1][j] == 'E'))
	{
		rt_map->map[i + 1][j] = 'P';
		flag = 1;
	}
	if ((j - 1 > 0) && (rt_map->map[i][j - 1] == '0'
		|| rt_map->map[i][j - 1] == 'C' || rt_map->map[i][j - 1] == 'E'))
	{
		rt_map->map[i][j - 1] = 'P';
		flag = 1;
	}
	if ((j + 1 < rt_map->row_num - 1) && (rt_map->map[i][j + 1] == '0'
		|| rt_map->map[i][j + 1] == 'C' || rt_map->map[i][j + 1] == 'E'))
	{
		rt_map->map[i][j + 1] = 'P';
		flag = 1;
	}
	return (flag);
}

int	is_01(char c)
{
	if (c == '1')
		return (1);
	if (c == '0')
		return (1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == 0 && s2[i] == 0)
		return (1);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strrchr(char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (str[i] != c && i > 0)
		i--;
	if (i == 0)
		return (ft_strlen(str) - 1);
	return (i);
}
