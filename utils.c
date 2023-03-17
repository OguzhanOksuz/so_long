/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:56:15 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/17 14:28:02 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
