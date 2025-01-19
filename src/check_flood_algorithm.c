/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood_algorithm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:25:33 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/19 08:02:35 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*check_flood_fill(char **map, int player_of_rows, int player_of_cols, int *C_count)
{
	static int collectable_flood = 0;
	static int exit_flood = 0;


	if (map[player_of_rows][player_of_cols] == '1')
        return NULL;
	if (map[player_of_rows][player_of_cols] == 'C')
		collectable_flood++;
	if (map[player_of_rows][player_of_cols] == 'E')
		exit_flood++;
	map[player_of_rows][player_of_cols] = '1';
	check_flood_fill(map, player_of_rows + 1, player_of_cols, C_count);
	check_flood_fill(map, player_of_rows - 1, player_of_cols, C_count);
	check_flood_fill(map, player_of_rows, player_of_cols + 1, C_count);
	check_flood_fill(map, player_of_rows, player_of_cols - 1, C_count);
	return (NULL);
}