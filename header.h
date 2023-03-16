/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:57:37 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/17 00:47:47 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define TRUE 1
# define FALSE 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_trim(char *rd);
char	*ft_line(char *rt, char *rd);
char	*ft_read(int fd, char *rt);
char	*get_next_line(int fd);
int	ft_strlen(const char *str);
int		ft_strchr(const char *s, int c);
int	ft_strrchr(char *str, int c);

typedef int t_bool;

typedef struct s_map
{
	int	row;
	int	column;
	t_bool	valid;
	char	*extension;
	char	**map;
} t_map;


#endif
