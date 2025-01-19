/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:09:28 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/19 19:53:33 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    before_move(t_game *game, int old_row, int old_col)
{
    if (game->map[old_row][old_col] == MAP_EXIT_OBJECT)
    {
        mlx_image_to_window(game->mlx, game->floor.floor_object, old_col * 64, old_row * 64);
        mlx_image_to_window(game->mlx, game->exit.exit_object, old_col * 64, old_row * 64);
    }
    else
        mlx_image_to_window(game->mlx, game->floor.floor_object, old_col * 64, old_row * 64);
}

void    after_move(t_game *game, int new_row, int new_col)
{
    if (game->map[new_row][new_col] == MAP_COLLECTIBLE_OBJECT)
    {
        game->map[new_row][new_col] = MAP_FLOOR_OBJECT;
        mlx_image_to_window(game->mlx, game->floor.floor_object, game->player.P_col * 64, game->player.P_row * 64);
        game->collected_collectibles_count++;
        printf("Collectibles: %d\n", game->collected_collectibles_count);
    }
    if (game->map[new_row][new_col] == MAP_EXIT_OBJECT
    && game->collected_collectibles_count == game->C_count)
    {
        printf("Exit reached\n");
        free_map_delete_object(game);
        mlx_close_window(game->mlx);
        mlx_terminate(game->mlx);
        free(game);
        exit(0);
    }
    else if (game->map[new_row][new_col] == MAP_EXIT_OBJECT
    && game->collected_collectibles_count != game->C_count)
        mlx_image_to_window(game->mlx, game->player.player_object, game->player.P_col * 64, game->player.P_row * 64);
    if (game->map[new_row][new_col] == MAP_PLAYER_OBJECT)
        mlx_image_to_window(game->mlx, game->player.player_object, game->player.P_col * 64, game->player.P_row * 64);
    if (game->map[new_row][new_col] == MAP_FLOOR_OBJECT)
        mlx_image_to_window(game->mlx, game->player.player_object, game->player.P_col * 64, game->player.P_row * 64);
}

void    objects_react(t_game *game, int row, int col)
{
    int new_row;
    int new_col;

    new_row = game->player.P_row + row;
    new_col = game->player.P_col + col;
    if (game->map[new_row][new_col] == MAP_WALL_OBJECT)
        return;
    before_move(game, game->player.P_row, game->player.P_col);
    game->player.P_row = new_row;
    game->player.P_col = new_col;
    after_move(game, game->player.P_row, game->player.P_col);
    game->player.P_count++;
    printf("%d\n", game->player.P_count);
}
        // free_map_delete_object(game);
        // mlx_terminate(game->mlx);
        // mlx_close_window(game->mlx);
        // exit(0);

static void behavior(struct mlx_key_data keydata, void *param)
{
    t_game *game = (t_game *)param;

    if (keydata.action != MLX_PRESS)
        return;

    if (keydata.key == MLX_KEY_ESCAPE)
    {
        free_map_delete_object(game);
        // Free any other dynamically allocated resources here
        mlx_terminate(game->mlx);
        mlx_close_window(game->mlx);
        free(game);
        exit(0);
    }
    if (keydata.key == MLX_KEY_W 
        || keydata.key == MLX_KEY_UP) 
        objects_react(game, -1, 0);
    else if (keydata.key == MLX_KEY_S 
        || keydata.key == MLX_KEY_DOWN) 
        objects_react(game,  +1, 0);
    else if (keydata.key == MLX_KEY_A 
        || keydata.key == MLX_KEY_LEFT)
        objects_react(game, 0, -1);
    else if (keydata.key == MLX_KEY_D 
        || keydata.key == MLX_KEY_RIGHT)
        objects_react(game, 0, +1);
}
// void game_complete(void *param)
// {
//     t_game *game;

//     game = (t_game *)param;
//     if (game->map[game->player.P_row][game->player.P_col] == MAP_EXIT_OBJECT)
//     {
//         if (game->collected_collectibles_count == game->C_count)
//         {
//             printf("Exit reached\n");
//             free_map_delete_object(game);
//             mlx_close_window(game->mlx);
//             mlx_terminate(game->mlx);
//         }
//     }
// }

void movement(t_game *game)
{
    mlx_key_hook(game->mlx, &behavior, game);
    // mlx_loop_hook(game->mlx, &game_complete, game);
}