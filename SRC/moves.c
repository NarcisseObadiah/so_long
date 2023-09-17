/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:11:45 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/08 15:12:04 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//function to load player link using the mlx functions

void	load_player(t_map *map, char direction)
{
	mlx_delete_image(map->mlx, map->image->player);
	if (direction == 'u')
	{
		map->image->player = mlx_texture_to_image(map->mlx, map->player_up);
		mlx_image_to_window(map->mlx, map->image->player, \
				map->player_x * PIXELS, map->player_y * PIXELS);
	}
	else if (direction == 'r')
	{
		map->image->player = mlx_texture_to_image(map->mlx, map->player_right);
		mlx_image_to_window(map->mlx, map->image->player, \
				map->player_x * PIXELS, map->player_y * PIXELS);
	}
	else if (direction == 'l')
	{
		map->image->player = mlx_texture_to_image(map->mlx, map->player_left);
		mlx_image_to_window(map->mlx, map->image->player, \
				map->player_x * PIXELS, map->player_y * PIXELS);
	}
	else if (direction == 'd')
	{
		map->image->player = mlx_texture_to_image(map->mlx, map->player_down);
		mlx_image_to_window(map->mlx, map->image->player, \
				map->player_x * PIXELS, map->player_y * PIXELS);
	}
}
//function to select a move depending  on  a given axe

void	select_move(t_map *map, char axe, char direction)
{
	if (axe == 'x')
	{
		if (direction == 'l')
			move_left(map);
		else
			move_right(map);
	}
	else if (axe == 'y')
	{
		if (direction == 'u')
			move_up(map);
		else
			move_down(map);
	}
}
/*All in one function wich contains the select move function 
	and the load player fucntion To allow the player  movement */

void	move_player(t_map *map, char axe, char direction)
{
	select_move(map, axe, direction);
	load_player(map, direction);
}

// function to detect the hooks by usig the MLX_PRESS
void	move_hook(mlx_key_data_t keydata, void *data)
{
	t_map	*map;

	map = (t_map *) data;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(map, 'y', 'u');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(map, 'x', 'r');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(map, 'y', 'd');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(map, 'x', 'l');
}
