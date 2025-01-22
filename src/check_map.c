/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:54:24 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/22 21:59:09 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	some_line_is_empty(t_game *game)
{
	if (game->current_length == 0)
		game->error = 1;
}
void	process_lines(t_game *game)
{
	static int	first_non_empty_line = 1;

	game->line = get_next_line(game->fd);
	while (game->line)
	{
		game->map[game->line_count] = ft_strdup(game->line);
		game->current_length = newline_to_terminated(game);
		some_line_is_empty(game);
		if (first_non_empty_line == 1)
		{
			handle_first_line(game);
			first_non_empty_line = 0;
		}
		else if (game->line_count == game->map_height)
			handle_last_line(game);
		else
			covered_by_one(game);
		printf("%ld: %s\n", game->line_count, game->map[game->line_count]);
		game->line_count++;
		free(game->line);
		game->line = get_next_line(game->fd);
	}
	if (game->error == 1)
		error_free_close(game);
}

// void	process_lines(t_game *game)
// {
// 	// static int	first_non_empty_line = 1;

// 	game->line = get_next_line(game->fd);
// 	while (game->line)
// 	{
// 		game->map[game->line_count] = ft_strdup(game->line);
// 		// game->current_length = newline_to_terminated(game);
// 		// some_line_is_empty(game);
// 		// if (game->line_count == game->map_height)
// 		// 	handle_last_line(game);
// 		// else if (first_non_empty_line == 1 && game->current_length != 0)
// 		// {
// 		// 	handle_first_line(game);
// 		// 	first_non_empty_line = 0;
// 		// }
// 		// else
// 		// 	covered_by_one(game);
// 		game->line_count++;
// 		printf("%s\n", game->map[game->line_count]);
// 		game->line = get_next_line(game->fd);
// 		free(game->line);
// 	}
// 	free_map(game);
// 	exit(0);
// 	if (game->error == 1)
// 		error_free_close(game);
// }

void	is_rectangle(t_game *game, char *file)
{
	game->fd = open_file(file);
	game->map_height = len_to_newline_in_file(file);
	if (game->map_height <= 1)
	{
		ft_putstr_fd("Error\nMap is too small\n", 2);
		exit(1);
	}
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	process_lines(game);
	free(game->last_line);
	free_map(game);	
	// game->map_width = game->first_line;
	close(game->fd);
}

void	check_ber(const char *av)
{
	int	len;

	len = ft_strlen(av);
	if (len < 4 || ft_strncmp(&av[len - 4], ".ber", 4) != 0)
	{
		write(2, "Error\nPlease provide a .ber file\n", 34);
		exit(EXIT_FAILURE);
	}
}

void	checks(t_game *game, char *file)
{
	is_rectangle(game, file);
	// game->P_count = 0;
	// game->C_count = 0;
	// game->E_count = 0;
	// count_check_element(game);
	// if (game->check_flood_pass == 0)
	// {
	// 	check_flood_fill(game, game->player.P_row, game->player.P_col);
	// 	// game->P_count = 0;
	// 	// game->C_count = 0;
	// 	// game->E_count = 0;
	// 	game->check_flood_pass = 1;
	// 	free_map(game);
	// }
}
