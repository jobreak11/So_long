/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:09:28 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/18 12:14:16 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    objects_react(t_game *game, int row, int col)
{
    int new_row;
    int new_col;

    new_row = game->player.P_row + row;
    new_col = game->player.P_col + col;
    // ถ้าตัวทางตันก็ไม่ทำอะไรอยู่ตำแหน่งเดิม
    //ตรวจดูตำแหน่งที่จะไปก่อนว่าเป็นกำแพงหรือไม่
    if (game->map[new_row][new_col] == MAP_WALL_OBJECT)
        return;
    //sectionตำแหน่งเดิม
    else if (game->map[game->player.P_row][game->player.P_col] == MAP_EXIT_OBJECT)
    {
        mlx_image_to_window(game->mlx, game->floor.floor_object, game->player.P_col * 64, game->player.P_row * 64);
        mlx_image_to_window(game->mlx, game->exit.exit_object, game->player.P_col * 64, game->player.P_row * 64);
    }
    else
        mlx_image_to_window(game->mlx, game->floor.floor_object, game->player.P_col * 64, game->player.P_row * 64);

    //เคสนี้ถ้าไปexitแล้วเก็บไม่ครบตัวละครจะวาดตัวละครอยู่ที่exit
    // if (game->map[game->player.P_row][game->player.P_col] == MAP_EXIT_OBJECT
    // && game->collected_collectibles_count != game->total_collectibles)
    // {
    //     mlx_image_to_window(game->mlx, game->exit.exit_object, game->player.P_col * 64, game->player.P_row * 64);
    //     mlx_image_to_window(game->mlx, game->player.player_object, game->player.P_col * 64, game->player.P_row * 64);
    // }
    game->player.P_row = new_row;
    game->player.P_col = new_col;
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
        game->exit_reached = 1;
    }
    else if (game->map[new_row][new_col] == MAP_EXIT_OBJECT
    && game->collected_collectibles_count != game->C_count)
        mlx_image_to_window(game->mlx, game->player.player_object, game->player.P_col * 64, game->player.P_row * 64);
    if (game->map[new_row][new_col] == MAP_PLAYER_OBJECT)
        mlx_image_to_window(game->mlx, game->player.player_object, game->player.P_col * 64, game->player.P_row * 64);
    if (game->map[new_row][new_col] == MAP_FLOOR_OBJECT)
        mlx_image_to_window(game->mlx, game->player.player_object, game->player.P_col * 64, game->player.P_row * 64);
    // game->map[game->player.P_row][game->player.P_col] = MAP_FLOOR_OBJECT;
    game->player.P_count++;
    printf("%d\n", game->player.P_count);
}


static void behavior(struct mlx_key_data keydata, void *param)
{
    t_game *game = (t_game *)param;

    if (keydata.action != MLX_PRESS)
        return;

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


void movement(t_game *game)
{
    mlx_key_hook(game->mlx, &behavior, game);
}