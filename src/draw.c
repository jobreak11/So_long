/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:10:28 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/20 23:01:00 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop_draw_grid_by_grid(t_game *game, int row)
{
	int	col;

	col = 0;
	while (game->map[row][col])
	{
		if (game->map[row][col] != '\n'
			&& game->map[row][col] != '\0')
		{
			if (game->map[row][col] == '1')
				mlx_image_to_window(game->mlx, WALL_OBJECT,
					col * 64, row * 64);
			else if (game->map[row][col] == 'P')
				mlx_image_to_window(game->mlx, PLAYER_OBJECT,
					col * 64, row * 64);
			else if (game->map[row][col] == 'C')
				mlx_image_to_window(game->mlx, COLLECTIBLE_OBJECT,
					col * 64, row * 64);
			else if (game->map[row][col] == 'E')
				mlx_image_to_window(game->mlx, EXIT_OBJECT,
					col * 64, row * 64);
			ft_printf("%c", game->map[row][col]);
		}
		col++;
	}
}

void	loop_draw_background(t_game *game, int row)
{
	int	column;

	column = 0;
	while (game->map[row][column])
	{
		if (game->map[row][column] != '\n'
		&& game->map[row][column] != '\0')
			mlx_image_to_window(game->mlx, game->floor.floor_object,
				column * 64, row * 64);
		column++;
	}
}

void	draw_background(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->map_height)
	{
		loop_draw_background(game, i);
		i++;
	}
}

void	draw_object_into_paper(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->map_height)
	{
		loop_draw_grid_by_grid(game, i);
		i++;
	}
}
