/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:10:41 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/11 16:01:26 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_one_line_in_file(char *file)
{
	int	i;
	int	len;
	int	fd;
	int	bytes_read;
	char buffer[1024];

	len = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nPlease provide a valid map\n", 32);
		exit(1);
	}
	while((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
				break;
			++len;
			++i;
		}
	}
	close(fd);
	return (len);
}

int	len_to_newline_in_file(char *file)
{
	int	i;
	int	len;
	int	fd;
	int	bytes_read;
	char	buffer[1024];
	
	len = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nPlease provide a valid map", 32);
		exit(1);
	}
	while((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
				++len;
			++i;
		}
	}
	close(fd);
	return (len);	
}
