/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood_algorithm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:25:33 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/11 15:59:44 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	print_map(char **map, int Position_player_of_rows, int Position_player_of_cols, char *s)
{
	int i = 0;
	static int j = 0;
	j++;
	printf("\nRound=%d check row=%d,col=%d", j, Position_player_of_rows, Position_player_of_cols);
	printf(" %s\n", s);
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}

char	*check_flood_fill(char **map, int Position_player_of_rows, int Position_player_of_cols, int *C_count)
{
	static int collectable_flood = 0;
	static int exit_flood = 0;


	if (map[Position_player_of_rows][Position_player_of_cols] == '1')
        return NULL;
	if (map[Position_player_of_rows][Position_player_of_cols] == 'C')
		collectable_flood++;
	if (map[Position_player_of_rows][Position_player_of_cols] == 'E')
		exit_flood++;
	print_map(map, Position_player_of_rows, Position_player_of_cols, "Before");
	map[Position_player_of_rows][Position_player_of_cols] = '1';
	printf(" row + 1");
	check_flood_fill(map, Position_player_of_rows + 1, Position_player_of_cols, C_count);
	printf(" row - 1");
	check_flood_fill(map, Position_player_of_rows - 1, Position_player_of_cols, C_count);
	printf(" col + 1");
	check_flood_fill(map, Position_player_of_rows, Position_player_of_cols + 1, C_count);
	printf(" col - 1");
	check_flood_fill(map, Position_player_of_rows, Position_player_of_cols - 1, C_count);
	if (collectable_flood == *C_count && exit_flood == 1)
		printf("Map is valid\n");
	return (NULL);
}