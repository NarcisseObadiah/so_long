/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:56:18 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/10 17:14:13 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_image	*load_player_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*player;

	player = mlx_load_png("Sprites/player.png");
	if (!player)
		error_msg("Png loading failed");
	image->player = mlx_texture_to_image(mlx, player);
	if (!image->player)
		error_msg("Texture to image failed");
	mlx_delete_texture(player);
	return (image);
}
