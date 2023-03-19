/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:43:55 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 15:07:57 by ooksuz           ###   ########.fr       */
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
/*
void	print_game(t_game *game)
{
	printf("move = %d\n", game->move);
	printf("player_i = %d\t", game->player_i);
	printf("player_j = %d\n", game->player_j);
	for (int i = 0; i < game->ren_map->row_num; i++)
		printf("%s\n", game->ren_map->map[i]);
	printf("coin = %d\n", game->ren_map->coin);
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

//	printf("key = %d\n", key);
//	print_game(game);	
//	render_engine(game);
//	
	return (1);
} */

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
	//	init_images(game);
	//	get_player_cordinates(game);
	//	print_game(game);
	//	mlx_hook(game->window, 2, 0, physics_engine, game);
	//	mlx_loop(game->mlx);
	//	render_engine(game);
	}
	(void) av;
	system("leaks so_long");
	return (0);
}
