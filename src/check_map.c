/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:54:24 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/14 21:55:25 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	some_line_is_empty(t_game *game)
{
	if (game->current_length == 0 
		&& game->line_count != game->map_height)
		game->error = 1;
}

void process_lines(t_game *game)
{
	static int first_non_empty_line = 1;

	game->line_count = 0;
	while ((game->line = get_next_line(game->fd)))
	{
		game->map[game->line_count] = strdup(game->line);
		game->current_length = newline_to_terminated(game);
		some_line_is_empty(game);
		if (game->error == 1)
			break;
		if (game->line_count == game->map_height) 
			handle_last_line(game);
		else if (first_non_empty_line == 1 && game->current_length != 0)
		{
			handle_first_line(game);
			first_non_empty_line = 0;
		}
		else
			covered_by_one(game);
		game->line_count++;
		free(game->line);
	}
	if (game->error == 1)
		error_free_close(game);
}

void is_rectangle(t_game *game, char *file)
{
	
	game->fd = open_file(file);
	game->map_height = len_to_newline_in_file(file);
	game->line_length = (int *)malloc(sizeof(int));
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	*game->line_length = -1;
	if (game->map_height <= 1)
	{
		error_free_close(game);
		return;
	}
	process_lines(game);
	game->map_width = game->first_line;
	write(1, "Map is rectangle\n", 18);
	close(game->fd);
}

void	check_ber(const char *av)
{
	int len = ft_strlen(av);
	if (len < 4 || ft_strncmp(&av[len - 4], ".ber", 4) != 0)
	{
		write(2, "Error\nPlease provide a .ber file\n", 34);
		exit(EXIT_FAILURE);
	}
}

void	checks(t_game *game ,char *file)
{

	size_t i = 0;
	is_rectangle(game, file);
    free(game->line_length);
    free(game->last_line);
	while (i < game->map_height + 1)
	{
		printf("%s", game->map[i]);
		i++;
	}
	count_check_element(game);
	// if (game->check_flood_pass == 0)
	// 	check_flood_fill(game->map, player_row, player_col, &game->C_count);
	// game->check_flood_pass = 1;
}