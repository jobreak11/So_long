/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood_algorithm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:25:33 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/20 23:02:14 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*check_flood_fill(t_game *game, int player_of_rows, int player_of_cols)
{
	static int	collectable_flood = 0;
	static int	exit_flood = 0;

	if (game->map[player_of_rows][player_of_cols] == '1')
		return (NULL);
	if (game->map[player_of_rows][player_of_cols] == 'C')
		collectable_flood++;
	if (game->map[player_of_rows][player_of_cols] == 'E')
		exit_flood++;
	game->map[player_of_rows][player_of_cols] = '1';
	check_flood_fill(game, player_of_rows + 1, player_of_cols);
	check_flood_fill(game, player_of_rows - 1, player_of_cols);
	check_flood_fill(game, player_of_rows, player_of_cols + 1);
	check_flood_fill(game, player_of_rows, player_of_cols - 1);
	if (collectable_flood != game->C_count && exit_flood != 1)
		flood_error_case_1(game);
	if (collectable_flood != game->C_count)
		flood_error_case_2(game);
	if (exit_flood != 1)
		flood_error_case_3(game);
	return (NULL);
}

void	flood_error_case_1(t_game *game)
{
	free_map(game);
	write(2, "Error\nCollectable and Exit is not reachable\n", 44);
	exit(1);
}

void	flood_error_case_2(t_game *game)
{
	free_map(game);
	write(2, "Error\nCollectable is not reachable\n", 35);
	exit(1);
}

void	flood_error_case_3(t_game *game)
{
	free_map(game);
	write(2, "Error\nExit is not reachable\n", 29);
	exit(1);
}
