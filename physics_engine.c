/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 04:28:11 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/19 04:56:48 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (1);
}

void to_left(t_game *game)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = game->player_j;
	j = game->player_i;
	if (j > 0)
	{
		if (game->ren_map[i][j - 1] == 'E')
			try_exit(game);
		if (game->ren_map[i][j - 1] != '1')
			game->move++;
		if (game->ren_map[i][j - 1] == 'X')
			error_code(-101010);
		if (game->ren_map[i][j - 1] == '0')
			flag = 1;
		if (game->ren_map[i][j - 1] == 'C')
		{
			game->ren_map->coin--;
			flag = 1;
		}
	}
	if (flag == 1)
		to_move(game, 0, -1);
}
