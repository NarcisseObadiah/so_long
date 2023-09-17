/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 05:03:33 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/04 18:37:52 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_image	*load_bush_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*bush;

	bush = mlx_load_png("Sprites/Bush.png");
	if (!bush)
		error_msg("Fail to load the png");
	image->bush = mlx_texture_to_image(mlx, bush);
	if (!image->bush)
		error_msg("Problem with texture and image!");
	mlx_delete_texture(bush);
	return (image);
}

t_image	*load_grass_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("Sprites/Grass.png");
	if (!grass)
		error_msg("Fail to load the png");
	image->grass = mlx_texture_to_image(mlx, grass);
	if (!image->grass)
		error_msg("Problem with texture and image!");
	mlx_delete_texture(grass);
	return (image);
}

t_image	*load_collect_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*collect;

	collect = mlx_load_png("Sprites/Collect.png");
	if (!collect)
		error_msg("Fail to load the png");
	image->collect = mlx_texture_to_image(mlx, collect);
	if (!image->collect)
		error_msg("Problem with texture and image!");
	mlx_delete_texture(collect);
	return (image);
}

t_image	*load_exit_closed_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("Sprites/Exit_Closed.png");
	if (!exit)
		error_msg("Fail to load the png");
	image->exit_closed = mlx_texture_to_image(mlx, exit);
	if (!image->exit_closed)
		error_msg("Problem with texture and image!");
	mlx_delete_texture(exit);
	return (image);
}

t_image	*load_exit_open_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("Sprites/Exit_Open.png");
	if (!exit)
		error_msg("Fail to load the png");
	image->exit_open = mlx_texture_to_image(mlx, exit);
	if (!image->exit_open)
		error_msg("Problem with texture and image!");
	mlx_delete_texture(exit);
	return (image);
}
