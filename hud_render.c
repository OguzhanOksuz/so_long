/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:31:28 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/27 20:46:43 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		c = (nb + 48);
		write(1, &c, 1);
	}
}

void	move_count(t_game *game)
{
	write(1, "move = ", 7);
	ft_putnbr(game->move);
	write(1, "\n", 1);
}

void	render_move_count(t_game *game)
{
	mlx_string_put(game->mlx, game->window, 0, 16, game->color << 16,
		"Move = ");
	mlx_string_put(game->mlx, game->window, 50, 16, game->color << 16,
		ft_itoa(game->move));
}	

void	render_coin_count(t_game *game)
{
	mlx_string_put(game->mlx, game->window, 0, 30, game->color << 16,
		"Coin = ");
	mlx_string_put(game->mlx, game->window, 50, 30, game->color << 16,
		ft_itoa(*game->coin));
}

void	hud_render(t_game *game)
{
	render_cordinate(game, 0, 0);
	render_cordinate(game, 0, 1);
	render_move_count(game);
	render_coin_count(game);
	game->color += game->delta;
	if (game->color == 255)
		game->delta = -1;
	if (game->color == 0)
		game->delta = 1;
}
