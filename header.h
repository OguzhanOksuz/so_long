/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:57:37 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/14 22:28:14 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define TRUE 1
# define FALSE 0

typedef int t_bool;

typedef struct s_map
{
	int	row;
	int	colmun;
	t_bool	readed;
	t_bool	valid;
	char	*extension;
	char	**map;
} t_map;

int	ft_strlen(char *str);
int	ft_strrchr(char *str, int c);

#endif
