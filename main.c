/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:43:55 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/18 02:25:10 by ooksuz           ###   ########.fr       */
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
	else if (code == -6 || code == -5 || code == -4)
		write(2, "Error invalid collectiable count\n", 34);
	else if (code == -7)
		write(2, "Error invalid wall design\n", 27);
	else if (code == -8)
		write(2, "Error unreachable component exist\n", 35);
	else if (code == -42)
		write(2, "Error invalid arguman count\n", 29);
	else if (code == -404)
		write(2, "Error file did not found\n", 26);
	else if (code == -101010)
		write(2, "You Dieded\n", 11);
	else if (code == -1024)
		write(2, "Exit\n", 5);
	else
		write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_map	*ren_map;
	int		fd;
	t_game	*game;

	if (ac != 2)
		return (error_code(-42));
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			close(fd);
			error_code(-404);
		}
		ren_map = map_init(av[1]);
		if (ren_map->valid < 0)
			error_code(ren_map->valid);
		game = init_game(ren_map);
		lunch_game(game);
	}
	system("leaks so_long");
	return (0);
}
