/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:29:43 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/20 23:01:17 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nCannot open file\n", 23);
		exit(1);
	}
	return (fd);
}

int	newline_to_terminated(t_game *game)
{
	int	current_length;

	current_length = ft_strlen(game->line);
	if (current_length > 0 && game->line[current_length - 1] == '\n')
	{
		game->line[current_length - 1] = '\0';
		current_length--;
	}
	return (current_length);
}

void	handle_first_line(t_game *game)
{
	*game->line_length = ft_strlen(game->line);
	game->first_line = *game->line_length;
	first_or_last_line_all_one(game);
}

void	handle_last_line(t_game *game)
{
	if (game->last_line)
		free(game->last_line);
	game->last_line = ft_strdup(game->line);
	if (ft_strlen(game->last_line) != game->first_line)
		game->error = 1;
	first_or_last_line_all_one(game);
}
