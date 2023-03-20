/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:43:55 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/20 16:10:40 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	error_code(int code)
{
	if (code == -1)
		write(2, "Error invalid extension\n", 25);
	else if (code == -2)
		write(2, "Error map is not rectangular\n", 30);
	else if (code == -3)
		write(2, "Error invalid component\n", 25);
	else if (code == -4)
		write(2, "Error invalid component count\n", 31);
	else if (code == -5)
		write(2, "Error invalid wall design\n", 27);
	else if (code == -6)
		write(2, "Error unreachable component exist\n", 35);
	else if (code == -42)
		write(2, "Error invalid arguman count\n", 29);
	else if (code == -404)
		write(2, "Error file did not found\n", 26);
	else if (code == -500)
		write(2, "Error Malloc\n", 14);
	else
		write(1, "Exit Game\n", 10);
	exit(1);
}

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

int	physics_engine(int key, t_game *game)
{
	if (key == 0)
		to_left(game);
	if (key == 1)
		to_down(game);
	if (key == 2)
		to_right(game);
	if (key == 13)
		to_up(game);
	if (key == 53)
		error_code(1);
	render_move(game, key);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error_code(-500);
	if (ac != 2)
		return (error_code(-42));
	else
	{
		game->map = map_init(av[1]);
		init_structs(game);
		init_images(game);
		render_map(game);
		mlx_hook(game->window, 2, 0, physics_engine, game);
		mlx_hook(game->window, 17, 0, error_code, NULL);
		mlx_loop(game->mlx);
	}
	return (0);
}
