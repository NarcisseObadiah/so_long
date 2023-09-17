/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:47:29 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/11 19:38:54 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	get_position(t_map *map, char target, char coordinate_type)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == target)
			{
				if (coordinate_type == 'x')
					return (x);
				else if (coordinate_type == 'y')
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
