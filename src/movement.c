/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:09:28 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/20 23:17:42 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	before_move(t_game *game, int old_row, int old_col)
{
	if (game->map[old_row][old_col] == MAP_EXIT_OBJECT)
	{
		mlx_image_to_window(game->mlx, FLOOR_OBJECT, old_col
			* 64, old_row * 64);
		mlx_image_to_window(game->mlx, EXIT_OBJECT, old_col
			* 64, old_row * 64);
	}
	else
		mlx_image_to_window(game->mlx, FLOOR_OBJECT, old_col
			* 64, old_row * 64);
}

void	after_move(t_game *game, int new_row, int new_col)
{
	if (game->map[new_row][new_col] == MAP_COLLECTIBLE_OBJECT)
	{
		game->map[new_row][new_col] = MAP_FLOOR_OBJECT;
		mlx_image_to_window(game->mlx, FLOOR_OBJECT, Pos_col
			* 64, Pos_row * 64);
		game->collected_collectibles_count++;
		ft_printf("Collected: %d\n", game->collected_collectibles_count);
	}
	if (game->map[new_row][new_col] == MAP_EXIT_OBJECT
	&& game->collected_collectibles_count == game->C_count)
	{
		mlx_close_window(game->mlx);
		ft_printf("Congratulations! You win!\n");
	}
	else if (game->map[new_row][new_col] == MAP_EXIT_OBJECT
	&& game->collected_collectibles_count != game->C_count)
		mlx_image_to_window(game->mlx, PLAYER_OBJECT, Pos_col
			* 64, Pos_row * 64);
	if (game->map[new_row][new_col] == MAP_PLAYER_OBJECT)
		mlx_image_to_window(game->mlx, PLAYER_OBJECT, Pos_col
			* 64, Pos_row * 64);
	if (game->map[new_row][new_col] == MAP_FLOOR_OBJECT)
		mlx_image_to_window(game->mlx, PLAYER_OBJECT, Pos_col
			* 64, Pos_row * 64);
}

void	objects_react(t_game *game, int row, int col)
{
	int	new_row;
	int	new_col;

	new_row = Pos_row + row;
	new_col = Pos_col + col;
	if (game->map[new_row][new_col] == MAP_WALL_OBJECT)
		return ;
	before_move(game, Pos_row, Pos_col);
	Pos_row = new_row;
	Pos_col = new_col;
	after_move(game, Pos_row, Pos_col);
	game->player.P_count++;
	ft_printf("Moves: %d\n", game->player.P_count);
}

static void	behavior(struct mlx_key_data keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W
		|| keydata.key == MLX_KEY_UP)
		objects_react(game, -1, 0);
	else if (keydata.key == MLX_KEY_S
		|| keydata.key == MLX_KEY_DOWN)
		objects_react(game, +1, 0);
	else if (keydata.key == MLX_KEY_A
		|| keydata.key == MLX_KEY_LEFT)
		objects_react(game, 0, -1);
	else if (keydata.key == MLX_KEY_D
		|| keydata.key == MLX_KEY_RIGHT)
		objects_react(game, 0, +1);
}

void	movement(t_game *game)
{
	mlx_key_hook(game->mlx, &behavior, game);
}
