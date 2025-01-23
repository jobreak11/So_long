/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:59:30 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/23 21:57:13 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	objects_init(t_game *game)
{
	FLOOR_BUFFER = mlx_load_png(FLOOR_PATH);
	PLAYER_BUFFER = mlx_load_png(PLAYER_PATH);
	WALL_BUFFER = mlx_load_png(WALL_PATH);
	COLLECTIBLE_BUFFER = mlx_load_png(COLLECTIBLE_PATH);
	EXIT_BUFFER = mlx_load_png(EXIT_PATH);
	FLOOR_OBJECT = mlx_texture_to_image(game->mlx, FLOOR_BUFFER);
	PLAYER_OBJECT = mlx_texture_to_image(game->mlx, PLAYER_BUFFER);
	WALL_OBJECT = mlx_texture_to_image(game->mlx, WALL_BUFFER);
	COLLECTIBLE_OBJECT = mlx_texture_to_image(game->mlx, COLLECTIBLE_BUFFER);
	EXIT_OBJECT = mlx_texture_to_image(game->mlx, EXIT_BUFFER);
}

void	game_init_set_zero(t_game *game)
{
	game->fd = 0;
	game->map_height = 0;
	game->map_width = 0;
	game->line = NULL;
	game->last_line = NULL;
	game->first_line = 0;
	game->current_length = 0;
	game->error = 0;
	game->is_empty = 0;
	game->map = NULL;
	game->position_x = 0;
	game->position_y = 0;
	game->player.P_col = 0;
	game->player.P_row = 0;
	game->player.P_count = 0;
	game->collectible.C_count = 0;
	game->exit.E_count = 0;
	game->collected_collectibles_count = 0;
	game->line_count = 0;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Usage: %s <map_file>\n", av[0]);
		return (1);
	}
	check_ber(av[1]);
	game.check_flood_pass = 0;
	game_init_set_zero(&game);
	checks(&game, av[1]);
	game_init_set_zero(&game);
	checks(&game, av[1]);
	game.mlx = mlx_init(MAP_WIDTH * 64, (MAP_HEIGHT + 1) * 64, "so_long", false);
	objects_init(&game);
	draw_background(&game);
	draw_object_into_paper(&game);
	ft_printf("\nCollectibles: %d\n", game.C_count);
	movement(&game);
	mlx_loop(game.mlx);
	free_map_delete_object(&game);
	return (0);
}
// 473,496 escape game passed
// 473,496 play win game passed

// int    main(int ac, char **av)  // 470,085 leak for laptop
// {
//     (void)ac;
//     (void)av;

//     mlx_t    *mlx;

//     mlx = mlx_init(400, 300, "test", true);
// 	mlx_loop(mlx);
//     mlx_terminate(mlx);
// }