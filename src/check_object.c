/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:16:41 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/20 22:18:01 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player(int P_count)
{
	if (P_count > 1)
	{
		write(2, "Error\nToo many players\n", 24);
		exit(1);
	}
	if (P_count == 0)
	{
		write(2, "Error\nNo player\n", 17);
		exit(1);
	}
}

void	check_collectable(int C_count)
{
	if (C_count == 0)
	{
		write(2, "Error\nNo collectable\n", 21);
		exit(1);
	}
}

void	check_exit(int E_count)
{
	if (E_count == 0)
	{
		write(2, "Error\nNo exit\n", 14);
		exit(1);
	}
	if (E_count > 1)
	{
		write(2, "Error\nToo many exits\n", 22);
		exit(1);
	}
}

void	check_elements(t_game *game, int check_rows, int check_cols)
{
	if (!game->map || !game->map[check_rows])
	{
		write(2, "Error\nMap row is NULL\n", 22);
		exit(1);
	}
	if (game->map[check_rows][check_cols] != 'P'
		&& game->map[check_rows][check_cols] != 'C'
		&& game->map[check_rows][check_cols] != 'E'
		&& game->map[check_rows][check_cols] != '1'
		&& game->map[check_rows][check_cols] != '0'
		&& game->map[check_rows][check_cols] != '\n')
	{
		write(2, "Error\nInvalid element in map\n", 30);
		exit(1);
	}
	if (game->map[check_rows][check_cols] == 'P')
	{
		game->P_count++;
		game->player.P_row = check_rows;
		game->player.P_col = check_cols;
	}
	if (game->map[check_rows][check_cols] == 'C')
		game->C_count++;
	if (game->map[check_rows][check_cols] == 'E')
		game->E_count++;
}

void	count_check_element(t_game *game)
{
	size_t	check_rows;
	size_t	check_cols;

	check_rows = 0;
	while (check_rows < game->line_count)
	{
		check_cols = 0;
		while (check_cols < game->first_line)
		{
			check_elements(game, check_rows, check_cols);
			check_cols++;
		}
		check_rows++;
	}
	check_player(game->P_count);
	check_collectable(game->C_count);
	check_exit(game->E_count);
}
