/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:40:02 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/08 15:14:18 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	checking_if_empty_lines(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if ((map[0] == '\n') || (map[i] == '\n' && (map[i + 1]) == '\n'))
			error_msg("This map contains empty lines!");
		i++;
	}
}

void	check_if_walls(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			error_msg("The map is not surrounded by walls");
		i++;
	}
	j = 0;
	while (j < map->height)
	{
		if (map->grid[j][0] != '1' || map->grid[j][map->width - 1] != '1')
			error_msg("The map is not surrounded by walls");
		j++;
	}
}
