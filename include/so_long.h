/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:25:16 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/15 19:51:40 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <memory.h>
# include <time.h>
# define PIXELS 64
# define EMOVE 30

typedef struct s_image {
	mlx_image_t			*bush;
	mlx_image_t			*grass;
	mlx_image_t			*collect;
	mlx_image_t			*player;
	mlx_image_t			*exit_closed;
	mlx_image_t			*exit_open;
}	t_image;

typedef struct s_map {
	char			**grid;
	size_t			width;
	size_t			height;
	size_t			collects;
	size_t			steps;
	size_t			collected;
	size_t			player_x;
	size_t			player_y;
	size_t			exit_x;
	size_t			exit_y;
	mlx_texture_t	*player_up;
	mlx_texture_t	*player_down;
	mlx_texture_t	*player_left;
	mlx_texture_t	*player_right;
	t_image			*image;
	mlx_t			*mlx;
}	t_map;

//Map

char	*read_map(char *map);
void	error_msg(char *msg);
size_t	count_collects(t_map *map);
size_t	count_row(char **grid);
t_map	*map_struct_init(char **grid);
t_map	*data_struct_init(char *map);
size_t	get_position(t_map *map, char target, char coordinate_type);

//Map validation
void	check_map_extension(char *file);
void	check_map_shape(char **grid);
void	check_map_content(char *map);
void	check_map_is_empty(char *map);
void	checking_if_empty_lines(char *map);
void	check_if_walls(t_map *map);
size_t	check_path(t_map *path, size_t y, size_t x);

void	free_grid(char **grid, size_t height);
void	flood_fill(t_map	*map);

//mlx image functions

t_image	*load_player_texture(mlx_t *mlx, t_image *image);
t_image	*load_bush_texture(mlx_t *mlx, t_image *image);
t_image	*load_grass_texture(mlx_t *mlx, t_image *image);
t_image	*load_collect_texture(mlx_t *mlx, t_image *image);
t_image	*load_exit_closed_texture(mlx_t *mlx, t_image *image);
t_image	*load_exit_open_texture(mlx_t *mlx, t_image *image);
t_image	*image_struct_init(mlx_t *mlx);
void	load_player(t_map *map, char direction);

void	select_image(t_map *data, size_t y, size_t x);
void	fill_background(t_map *data);
void	rend_map(t_map *data);
void	move_hook(mlx_key_data_t keydata, void *data);

t_map	*move_left(t_map *map);
t_map	*move_up(t_map *map);
t_map	*move_down(t_map *map);
t_map	*move_right(t_map *map);
void	remove_collect(t_map *map, int y, int x);
void	check_map_status(t_map *map);

#endif