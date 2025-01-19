/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:59:30 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/19 19:50:47 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	objects_init(t_game *game)
{
	game->floor.texture = mlx_load_png("./content/grass.png");
	game->player.player_buffer = mlx_load_png("./content/Player.png");
	game->wall.wall_buffer = mlx_load_png("./content/wall.png");
	game->collectible.collectible_buffer = mlx_load_png("./content/Collectable.png");
	game->exit.exit_buffer = mlx_load_png("./content/exit.png");
	game->floor.floor_object = mlx_texture_to_image(game->mlx, game->floor.texture);
	game->player.player_object = mlx_texture_to_image(game->mlx, game->player.player_buffer);
	game->wall.wall_object = mlx_texture_to_image(game->mlx, game->wall.wall_buffer);
	game->collectible.collectible_object = mlx_texture_to_image(game->mlx, game->collectible.collectible_buffer);
	game->exit.exit_object = mlx_texture_to_image(game->mlx, game->exit.exit_buffer);
}

void	game_init_set_zero(t_game *game)
{
	game->fd = 0;
	game->map_height = 0;
	game->line = NULL;
	game->line_length = NULL;
	game->last_line = NULL;
	game->line_count = 0;
	game->first_line = 0;
	game->current_length = 0;
	game->error = 0;
	game->map = NULL;
	game->position_x = 0;
	game->position_y = 0;
	game->player.P_col = 0;
	game->player.P_row = 0;
	game->player.P_count = 0;
	game->collectible.C_count = 0;
	game->exit.E_count = 0;
	game->collected_collectibles_count = 0;
}

int main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		printf("Usage: %s <map_file>\n", av[0]);
		return 1;
	}
    check_ber(av[1]);
	game.check_flood_pass = 0;
	game_init_set_zero(&game);
	checks(&game , av[1]);
	checks(&game , av[1]);
	game.mlx = mlx_init(game.map_width * 64, game.map_height * 64, "so_long", false);
	objects_init(&game);
	draw_background(&game);
	draw_object_into_paper(&game);
	printf("\nCollectibles: %d\n", game.C_count);
	movement(&game);;
	mlx_loop(game.mlx);
	free_map_delete_object(&game);
	mlx_close_window(game.mlx);
	mlx_terminate(game.mlx);
    return (0);
}

// int    main(int ac, char **av)  // 470,085 leak for laptop
// {
//     (void)ac;
//     (void)av;

//     mlx_t    *mlx;

//     mlx = mlx_init(400, 300, "test", true);
// 	mlx_loop(mlx);
//     mlx_terminate(mlx);
// }