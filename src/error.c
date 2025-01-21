/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:34:11 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/20 23:16:00 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_delete_object(t_game *game)
{
	mlx_delete_texture(FLOOR_BUFFER);
	mlx_delete_texture(PLAYER_BUFFER);
	mlx_delete_texture(WALL_BUFFER);
	mlx_delete_texture(COLLECTIBLE_BUFFER);
	mlx_delete_texture(EXIT_BUFFER);
	mlx_delete_image(game->mlx, FLOOR_OBJECT);
	mlx_delete_image(game->mlx, PLAYER_OBJECT);
	mlx_delete_image(game->mlx, WALL_OBJECT);
	mlx_delete_image(game->mlx, COLLECTIBLE_OBJECT);
	mlx_delete_image(game->mlx, EXIT_OBJECT);
	free_map(game);
}

void	free_map(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	error_free_close(t_game *game)
{
	if (game->line)
		free(game->line);
	if (game->line_length)
		free(game->line_length);
	if (game->last_line)
		free(game->last_line);
	free_map(game);
	write(2, "Error\nMap is not a rectangle\n", 29);
	close(game->fd);
	exit(1);
}

void	last_line_is_empty(t_game *game)
{
	close(game->fd);
	free_map(game);
	ft_printf("last line is null\n");
	exit(1);
}

void	last_line_not_equal_first(t_game *game)
{
	close(game->fd);
	free_map(game);
	ft_printf("last line not equal first\n");
	exit(1);
}
