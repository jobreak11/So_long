/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:59:30 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/12 14:22:03 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	objects_init(t_game *game)
{
	game->floor.texture = mlx_load_png("../content/grass.png");
	game->player.player_buffer = mlx_load_png("../content/Player.png");
	game->wall.wall_buffer = mlx_load_png("../content/wall.png");
	game->collectible.collectible_buffer = mlx_load_png("../content/Collectable.png");
	game->exit.exit_buffer = mlx_load_png("../content/exit.png");
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
	game->P_count = 0;
	game->C_count = 0;
	game->E_count = 0;
	game->player.P_col = 0;
	game->player.P_row = 0;
	game->player.P_count = 0;
	game->collectible.C_count = 0;
	game->exit.E_count = 0;
}

int main(int ac, char **av)
{
	t_game game;

    if (ac != 2)
    {
        printf("Usage: %s <map_file>\n", av[0]);
        return 1;
    }
    check_ber(av[1]);
	game_init_set_zero(&game);
	checks(&game , av[1]);
	// checks(&game , av[1]);
	// process_lines(&game);
	game.map_height += 1;
	game.mlx = mlx_init(game.map_width * 64, game.map_height * 64, "so_long", false);
	objects_init(&game);
	draw_background(&game);
	draw_object_into_paper(&game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
    return (0);
}

// int32_t	main(int ac, char *av[])
// {
// 	mlx_t* mlx;
	

// 	if (ac != 2)
// 	{
// 		write(2, "Error\nPlease provide a map file at the argument\n", 48);
// 		return (EXIT_FAILURE);
// 	}
// 	check_ber(av[1]);
// 	mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
// 	if (!mlx)
// 	{
// 		write(2, mlx_strerror(mlx_errno), strlen(mlx_strerror(mlx_errno)));
// 		return (EXIT_FAILURE);
// 	}
// 	mlx_loop(mlx);
// }


// int32_t	main(void)
// {
// 	// Start mlx
// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
// 	if (!mlx)
//         error();

// 	// Try to load the file
// 	mlx_texture_t* texture = mlx_load_png("../sprites/background.png");
// 	if (!texture)
//         error();
	

		
// 	// Convert texture to a displayable image
// 	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
// 	if (!img)
//         error();
// 	// Display the image
	
// 	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
//         error();

// 	mlx_texture_t* texture2 = mlx_load_png("../sprites/Idle (1).png");
// 	if (!texture2)
// 		error();
	
// 	g_img = mlx_texture_to_image(mlx, texture2);
// 	if (!g_img)
// 		error();
// 	if (mlx_image_to_window(mlx, g_img, 0, 0))
// 		error();
// 	mlx_loop_hook(mlx, &hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_delete_image(mlx, img);
// 	mlx_delete_texture(texture);
// 	mlx_delete_image(mlx, g_img);
// 	mlx_delete_texture(texture2);
//         // Optional, terminate will clean up any leftover images (not textures!)
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }





// int32_t	main(void)
// {
// 	mlx_t*    mlx;

// 	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
// 	if (!mlx)
// 		exit(EXIT_FAILURE);
// 	g_img = mlx_new_image(mlx, 128, 128);
// 	mlx_image_to_window(mlx, g_img, 0, 0);
// 	mlx_loop_hook(mlx, &hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

// hook concept
// void my_keyhook(mlx_key_data_t keydata, void* param)
// {
// 	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
// 		puts("Hello ");

// 	// If we RELEASE the 'K' key, print "World".
// 	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
// 		puts("World");

// 	// If we HOLD the 'L' key, print "!".
// 	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
// 		puts("!");
// }

// int32_t	main(void)
// {
// 	mlx_t* mlx;

// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 		return (EXIT_FAILURE);

// 	mlx_key_hook(mlx, &my_keyhook, NULL);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }


// color part
// static void ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(1);	
// }
// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// 	// mlx_t* mlx = param;
// 	// if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 	// 	mlx_close_window(mlx);
// }


// int32_t	main(void)
// {
//     mlx_set_setting(MLX_MAXIMIZED, true);
// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
// 	if (!mlx)
// 		ft_error();

// 	/*Do stuff*/

// 	mlx_image_t* image = mlx_new_image(mlx, 256, 256);

// 	memset(image->pixels, 255, image->width * image->height * BPP);
// 	if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
// 		ft_error();

// 	mlx_put_pixel(image, 0, 0, 0x00FF0000);
	
// 	mlx_loop_hook(mlx, ft_hook, mlx);
//     mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (0);
// }



// complie this file by using this command:
// cc main.c ../MLX42/build/libmlx42.a -I../MLX42/include -L../MLX42/lib -ldl -lglfw -pthread -lm