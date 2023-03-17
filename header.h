/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:57:37 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/17 19:59:16 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	**ft_split(const char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_trim(char *rd);
char	*ft_read(int fd);
int		ft_strlen(const char *str);
int		ft_strrchr(char *str, int c);
int		ft_strcmp(char *s1, char *s2);
int		is_01(char c);

typedef struct s_map
{
	int		row_len;
	int		row_num;
	int		valid;
	int		player;
	int		coin;
	int		exit;
	int		enemy;
	int		wrong;
	char	*extension;
	char	**map;
}	t_map;

#endif
