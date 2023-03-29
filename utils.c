/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:56:15 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/29 03:18:02 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_01(char c)
{
	if (c == '1')
		return (1);
	if (c == '0')
		return (1);
	return (0);
}

int	is_file_exist(char *src)
{
	int	fd;

	fd = open(src, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
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
	while (str[i] != c && i >= 0)
		i--;
	if (i == 0 && str[i] != c)
		return (ft_strlen(str) - 1);
	return (i);
}
