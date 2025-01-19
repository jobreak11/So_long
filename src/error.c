/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:34:11 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/19 14:21:38 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void    free_map_delete_object(t_game *game)
// {
//     mlx_delete_texture(game->floor.texture);
//     mlx_delete_texture(game->player.player_buffer);
//     mlx_delete_texture(game->wall.wall_buffer);
//     mlx_delete_texture(game->collectible.collectible_buffer);
//     mlx_delete_texture(game->exit.exit_buffer);
//     mlx_delete_image(game->mlx, game->floor.floor_object);
//     mlx_delete_image(game->mlx, game->player.player_object);
//     mlx_delete_image(game->mlx, game->wall.wall_object);
//     mlx_delete_image(game->mlx, game->collectible.collectible_object);
//     mlx_delete_image(game->mlx, game->exit.exit_object);
//     free_map(game);
// }

void    free_map_delete_object(t_game *game)
{
    mlx_delete_texture(game->floor.texture);
    mlx_delete_texture(game->player.player_buffer);
    mlx_delete_texture(game->wall.wall_buffer);
    mlx_delete_texture(game->collectible.collectible_buffer);
    mlx_delete_texture(game->exit.exit_buffer);
    mlx_delete_image(game->mlx, game->floor.floor_object);
    mlx_delete_image(game->mlx, game->player.player_object);
    mlx_delete_image(game->mlx, game->wall.wall_object);
    mlx_delete_image(game->mlx, game->collectible.collectible_object);
    mlx_delete_image(game->mlx, game->exit.exit_object);
    free_map(game);
}

void free_map(t_game *game)
{
	size_t i;

	i = 0;
    while(i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void error_free_close(t_game *game)
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

