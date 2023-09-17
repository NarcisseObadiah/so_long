/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:03:56 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/08 15:18:37 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//This function remove collectibles when

void	remove_collect(t_map *map, int y, int x)
{
	size_t	collect_i;

	collect_i = 0;
	x = x * 64 + 16;
	y = y * 64 + 16;
	while (collect_i < map->image->collect->count)
	{		
		if (map->image->collect->instances[collect_i].x == x
			&& map->image->collect->instances[collect_i].y == y)
		{
			map->image->collect->instances[collect_i].enabled = false;
		}
		collect_i++;
	}
}

t_map	*move_up(t_map *map)
{
	if (map->grid[map->player_y - 1][map->player_x] != '1'
		&& map->grid[map->player_y - 1][map->player_x] != 'E')
	{
		if (map->grid[map->player_y - 1][map->player_x] == 'C')
		{
			remove_collect(map, map->player_y - 1, map->player_x);
			map->grid[map->player_y - 1][map->player_x] = '0';
			map->collected += 1;
		}
		map->player_y -= 1;
		map->image->player->instances[0].y -= 1 * PIXELS;
		map->steps += 1;
		ft_printf("Number of moves : %d\n", map->steps);
	}
	check_map_status(map);
	return (map);
}

t_map	*move_down(t_map *map)
{
	if (map->grid[map->player_y + 1][map->player_x] != '1'
		&& map->grid[map->player_y + 1][map->player_x] != 'E')
	{
		if (map->grid[map->player_y + 1][map->player_x] == 'C')
		{
			remove_collect(map, map->player_y + 1, map->player_x);
			map->grid[map->player_y + 1][map->player_x] = '0';
			map->collected += 1;
		}
		map->player_y += 1;
		map->image->player->instances[0].y += 1 * PIXELS;
		map->steps += 1;
		ft_printf("Number of moves : %d\n", map->steps);
	}
	check_map_status(map);
	return (map);
}

t_map	*move_right(t_map *map)
{
	if (map->grid[map->player_y][map->player_x + 1] != '1'
		&& map->grid[map->player_y][map->player_x + 1] != 'E')
	{
		if (map->grid[map->player_y][map->player_x + 1] == 'C')
		{
			remove_collect(map, map->player_y, map->player_x + 1);
			map->grid[map->player_y][map->player_x + 1] = '0';
			map->collected += 1;
		}
		map->player_x += 1;
		map->image->player->instances[0].x += 1 * PIXELS;
		map->steps += 1;
		ft_printf("Number of moves : %d\n", map->steps);
	}
	check_map_status(map);
	return (map);
}

t_map	*move_left(t_map *map)
{
	if (map->grid[map->player_y][map->player_x - 1] != '1'
		&& map->grid[map->player_y][map->player_x - 1] != 'E')
	{
		if (map->grid[map->player_y][map->player_x - 1] == 'C')
		{
			remove_collect(map, map->player_y, map->player_x - 1);
			map->grid[map->player_y][map->player_x - 1] = '0';
			map->collected += 1;
		}
		map->player_x -= 1;
		map->image->player->instances[0].x -= 1 * PIXELS;
		map->steps += 1;
		ft_printf("Number of moves : %d\n", map->steps);
	}
	check_map_status(map);
	return (map);
}
