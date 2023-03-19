/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:43:55 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 23:38:02 by ooksuz           ###   ########.fr       */
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
	else if (code == -101010)
		write(2, "You Dieded\n", 11);
	else if (code == -1024)
		write(2, "Exit\n", 5);
	else if (code == -500)
		write(2, "Error Malloc\n", 14);
	else
		write(2, "Error\n", 6);
	exit(1);
}

int	physics_engine(int key, t_game *game)
{
	if (key == 0 || key == 123)
		to_left(game);
	if (key == 1 || key == 125)
		to_down(game);
	if (key == 2 || key == 124)
		to_right(game);
	if (key == 13 || key == 126)
		to_up(game);

	render_move(game, key);
	render_cordinate(game, game->exit_i, game->exit_j);
	print_game(game);
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
		if (game->map->enemies != 0)
			error_code(-3);
		init_structs(game);
		init_images(game);
		render_map(game);
		mlx_hook(game->window, 2, 0, physics_engine, game);
		mlx_loop(game->mlx);
	}
	system("leaks so_long");
	return (0);
}
