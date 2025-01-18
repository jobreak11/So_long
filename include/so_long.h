/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:02:30 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/17 20:42:31 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "MLX42/MLX42.h"
# include "libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>

# define MAP_EXIT_OBJECT 'E'
# define MAP_PLAYER_OBJECT 'P'
# define MAP_COLLECTIBLE_OBJECT 'C'
# define MAP_WALL_OBJECT '1'
# define MAP_FLOOR_OBJECT '0'

# define ERROR_ARGS "Error\nPlease provide a map file at the argument\n"
# define ERROR_BER "Error\nPlease provide a .ber file\n"
# define ERROR_MAP "Error\nInvalid map\n"
# define ERROR_EMPTY_MAP "Error\nEmpty map\n"
# define ERROR_MAP_RECTANGLE "Error\nMap is not a rectangle\n"
# define ERROR_MAP_WALL "Error\nMap is not surrounded by walls\n"
# define ERROR_MAP_PLAYER "Error\nMap has no player\n"
# define ERROR_MAP_COLLECTIBLE "Error\nMap has no collectible\n"
# define ERROR_MAP_EXIT "Error\nMap has no exit\n"

#define WIDTH 512
#define HEIGHT 512


typedef struct s_floor {
	mlx_texture_t *texture;
	mlx_image_t	*floor_object;
} t_floor;

typedef struct s_wall {
	mlx_texture_t *wall_buffer;
	mlx_image_t *wall_object;
} t_wall;

typedef struct s_player {
	mlx_texture_t *player_buffer;
	mlx_image_t	*player_object;
	int P_row;
	int P_col;
	int P_count;
} t_player;

typedef struct s_collectible {
	mlx_texture_t *collectible_buffer;
	mlx_image_t	*collectible_object;
	int C_count;
} t_collectible;

typedef struct s_exit {
	mlx_texture_t *exit_buffer;
    mlx_image_t *exit_object;
    int E_count;
} t_exit;

typedef struct s_image {
	t_floor floor;
	t_player player;
	t_collectible collectible;
	t_exit exit;
} t_image;

typedef struct s_game {
    action_t action;
	mlx_t *mlx;
	char **map;
	int	check_flood_pass;
	t_image image;
	t_floor floor;
	t_player player;
	t_collectible collectible;
	t_exit exit;
	t_wall wall;
	void *window;
	int map_width;
	size_t map_height;
	int position_x;
	int position_y;
	int player_moves;
	int total_collectibles;
	int collected_collectibles_count;
	int exit_reached;
	size_t first_line;
	int	fd;
	size_t	line_count;
	int	*line_length;
	int current_length;
	char *line;
	char *last_line;
	int	error;
	int C_count;
	int E_count;
	int P_count;
} t_game;


void 	first_or_last_line_all_one(t_game *game);
void	objects_init(t_game *game);
void	check_ber(const char *av);
void 	checks(t_game *game ,char *file);
void	is_rectangle(t_game *game, char *file);
int		len_to_newline_in_file(char *file);
int		open_file(char *file);
void	process_lines(t_game *game);
int		newline_to_terminated(t_game *game);
void	some_line_is_empty(t_game *game);
void	handle_first_line(t_game *game);
void	handle_last_line(t_game *game);
void	covered_by_one(t_game *game);
void	objects_init(t_game *game);
void	error_free_close(t_game *game);
void 	free_map(t_game *game);

void	count_check_element(t_game *game);
void 	check_elements(t_game *game, int check_rows, int check_cols);
void	check_player(int P_count);
void	check_collectable(int C_count);
void	check_exit(int E_count);

void	draw_background(t_game *game);
void	loop_draw_background(t_game *game, int row);
void	draw_object_into_paper(t_game *game);
void	loop_draw_grid_by_grid(t_game* game, int row);

void    movement(t_game *game);
void    objects_react(t_game *game, int row, int col);

#endif