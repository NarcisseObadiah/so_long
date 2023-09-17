/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:51:18 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/15 19:51:27 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_image	*images;

	if (argc != 2)
		error_msg("No file is given!");
	check_map_extension(argv[1]);
	map = data_struct_init(argv[1]);
	map->mlx = mlx_init(map->width * PIXELS,
			map->height * PIXELS, "so_long", true);
	if (!map->mlx)
		return (EXIT_FAILURE);
	images = image_struct_init(map->mlx);
	map->image = images;
	fill_background(map);
	rend_map(map);
	mlx_key_hook(map->mlx, move_hook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	return (EXIT_SUCCESS);
}
