/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:14:15 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/08 14:27:52 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	select_image(t_map *data, size_t y, size_t x)
{
	size_t	image_size;

	image_size = 32;
	if (data->grid[y][x] == '1')
		if (mlx_image_to_window(data->mlx, data->image->bush,
				x * PIXELS, y * PIXELS) < 0)
			error_msg("Failed to load the image to the window");
	if (data->grid[y][x] == 'C')
		if (mlx_image_to_window(data->mlx, data->image->collect,
				x * PIXELS + image_size / 2, y * PIXELS + image_size / 2) < 0)
			error_msg("Failed to load the image to the window");
	if (data->grid[y][x] == 'P')
		if (mlx_image_to_window(data->mlx, data->image->player,
				x * PIXELS, y * PIXELS) < 0)
			error_msg("Failed to load the image to the window");
	if (data->grid[y][x] == 'E')
		if (mlx_image_to_window(data->mlx, data->image->exit_closed,
				x * PIXELS, y * PIXELS) < 0)
			error_msg("Failed to load the image to the window");
}
//This function is to fill the background with the grass

void	fill_background(t_map *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (mlx_image_to_window(data->mlx, data->image->grass,
					x * PIXELS, y * PIXELS) < 0)
				error_msg("Failed to load the image to the window");
			x++;
		}
		y++;
	}
}
//This function  is to rend the map

void	rend_map(t_map *data)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			select_image(data, y, x);
			x++;
		}
		y++;
	}
}
