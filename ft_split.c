/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:18:07 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/17 14:25:54 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	char	*rt;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	rt = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s1[i])
	{
		rt[i] = s1[i];
		i++;
	}
	while (*s2)
		rt[i++] = *s2++;
	rt[i] = 0;
	free(s1);
	return (rt);
}

char	*ft_read(int fd)
{
	char	*rd;
	int		count;
	char	*rt;

	rt = NULL;
	count = 1;
	rd = (char *)malloc(sizeof(char) * (42 + 1));
	while (count > 0)
	{
		count = read(fd, rd, 42);
		if (count == -1)
		{
			free(rd);
			return (NULL);
		}
		rd[count] = 0;
		rt = ft_strjoin(rt, rd);
	}
	free (rd);
	return (rt);
}
