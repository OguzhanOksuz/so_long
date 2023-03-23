/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:54:27 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/23 21:39:24 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	render_cordinate(t_game *game, int i, int j)
{
	draw_floor(game, i, j);
	if (game->map->map[i][j] == '1')
		draw_wall(game, i, j);
	if (game->map->map[i][j] == 'E')
		draw_exit(game, i, j);
}

void	render_move(t_game *game, int code)
{
	animate_player(game, game->player);
	if (code == 0)
		render_cordinate(game, *game->player_i, *game->player_j + 1);
	if (code == 1)
		render_cordinate(game, *game->player_i - 1, *game->player_j);
	if (code == 2)
		render_cordinate(game, *game->player_i, *game->player_j - 1);
	if (code == 13)
		render_cordinate(game, *game->player_i + 1, *game->player_j);
	game->move++;
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			render_cordinate(game, i, j);
		}
	}
}

int	ft_digit(long int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		digit = 1;
	if (n < 0)
	{
		n *= -1;
		digit++;
	}
	while (n > 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	int			digit;
	int			i;
	char		*rt;
	long int	nb;

	nb = (long int)n;
	i = 0;
	digit = ft_digit(nb);
	rt = (char *)malloc(sizeof(char) * (digit + 1));
	if (!rt)
		return (0);
	rt[digit] = 0;
	if (nb < 0)
	{
		rt[i++] = '-';
		nb = -nb;
	}
	while (i <= --digit)
	{
		rt[digit] = nb % 10 + 48;
		nb /= 10;
	}
	return (rt);
}
