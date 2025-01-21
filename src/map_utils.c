/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:10:41 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/20 23:20:13 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_to_newline_in_file(char *file)
{
	int		i;
	int		len;
	int		fd;
	int		bytes_read;
	char	buffer[1024];

	len = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	fd_is_minus_one(fd);
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
				++len;
			++i;
		}
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	++len;
	close(fd);
	return (len);
}

void	first_or_last_line_all_one(t_game *game)
{
	size_t	i;

	i = 0;
	game->error = 0;
	if (!game->line)
		error_free_close(game);
	while (game->line[i] != '\0')
	{
		if (game->line[i] != '1')
		{
			game->error = 1;
			break ;
		}
		i++;
	}
}

void	covered_by_one(t_game *game)
{
	int	len;

	len = ft_strlen(game->line);
	if (game->line[0] != '1')
	{
		game->error = 1;
		ft_printf("Error: First character is not '1'.\n");
		return ;
	}
	if (game->line[len - 1] != '1')
	{
		game->error = 1;
		ft_printf("Error: Last character is not '1'.\n");
		return ;
	}
}

void	fd_is_minus_one(int fd)
{
	if (fd < 0)
	{
		write(2, "Error\nPlease provide a valid map", 32);
		exit(1);
	}
}
