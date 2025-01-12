/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:34:11 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/12 14:15:03 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(t_game *game)
{
	size_t i;

	i = 0;
    while(i < game->map_height + 1)
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

