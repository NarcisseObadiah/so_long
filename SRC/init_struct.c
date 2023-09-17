/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:25:09 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/11 20:00:24 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void	load_player_textures(t_map *map)
{
	map->player_up = mlx_load_png("Sprites/player_up.png");
	if (!map->player_up)
		error_msg("Failed to load png");
	map->player_down = mlx_load_png("Sprites/player_down.png");
	if (!map->player_down)
		error_msg("Failed to load png");
	map->player_left = mlx_load_png("Sprites/player_left.png");
	if (!map->player_left)
		error_msg("Failed to load png");
	map->player_right = mlx_load_png("Sprites/player_right.png");
	if (!map->player_right)
		error_msg("Failed to load png");
}

t_map	*map_struct_init(char **grid)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		error_msg("Struct memory allocation failed");
	map->grid = grid;
	map->width = ft_strlen(grid[0]);
	map->height = count_row(grid);
	map->collects = count_collects(map);
	map->steps = 0;
	map->player_x = get_position(map, 'P', 'x');
	map->player_y = get_position(map, 'P', 'y');
	map->exit_x = get_position(map, 'E', 'x');
	map->exit_y = get_position(map, 'E', 'y');
	load_player_textures(map);
	return (map);
}

t_map	*data_struct_init(char *map)
{
	char	*map_str;
	char	**map_array;
	t_map	*data;

	map_str = read_map(map);
	check_map_is_empty(map_str);
	checking_if_empty_lines(map_str);
	check_map_content(map_str);
	map_array = ft_split(map_str, '\n');
	check_map_shape(map_array);
	data = map_struct_init(map_array);
	check_if_walls(data);
	flood_fill(data);
	free(map_str);
	return (data);
}

t_image	*image_struct_init(mlx_t *mlx)
{
	t_image	*assets;

	assets = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!assets)
		return (NULL);
	assets = load_grass_texture(mlx, assets);
	assets = load_bush_texture(mlx, assets);
	assets = load_collect_texture(mlx, assets);
	assets = load_player_texture(mlx, assets);
	assets = load_exit_open_texture(mlx, assets);
	assets = load_exit_closed_texture(mlx, assets);
	return (assets);
}
