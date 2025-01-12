/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:10:28 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/12 14:10:33 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop_draw_grid_by_grid(t_game* game, int row)
{
	int	column;

	column = 0;
	while (game->map[row][column])
	{
		if (game->map[row][column] != '\n'
			&& game->map[row][column] != '\0')
		{
			if (game->map[row][column] == '1')
				mlx_image_to_window(game->mlx, game->wall.wall_object, column * 64, row * 64);
			else if (game->map[row][column] == 'P')
				mlx_image_to_window(game->mlx, game->player.player_object, column * 64, row * 64);
			else if (game->map[row][column] == 'C')
				mlx_image_to_window(game->mlx, game->collectible.collectible_object, column * 64, row * 64);
			else if (game->map[row][column] == 'E')
				mlx_image_to_window(game->mlx, game->exit.exit_object, column * 64, row * 64);
			printf("%c", game->map[row][column]);
		}
		column++;
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
			mlx_image_to_window(game->mlx, game->floor.floor_object, column * 64, row * 64);
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
	while(i < game->map_height)
	{
		loop_draw_grid_by_grid(game, i);
		i++;
	}
}