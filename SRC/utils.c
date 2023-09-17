/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:50:55 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/10 20:57:45 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_msg(char *msg)
{
	ft_putstr_fd("Error!\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	check_map_status(t_map *map)
{
	if (map->collected == map->collects)
	{
		if (mlx_image_to_window(map->mlx, map->image->exit_open,
				map->exit_x * PIXELS, map->exit_y * PIXELS) < 0)
			error_msg("Failed to load image to window");
		map->grid[map->exit_y][map->exit_x] = '0';
		if (map->player_x == map->exit_x && map->player_y == map->exit_y)
		{
			sleep(0);
			mlx_close_window(map->mlx);
			ft_putstr_fd("Congratulations!\n", 2);
			ft_putstr_fd("You are rich! 💰💰💰\n", 2);
			ft_putstr_fd("You can now buy anything you want!!!\n", 2);
		}
	}
}
