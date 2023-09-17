/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 02:32:40 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/11 19:48:21 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_grid(char **grid, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

size_t	check_path(t_map *path, size_t y, size_t x)
{
	if (y >= path->height || x >= path->width)
		return (0);
	if (path->grid[y][x] == '1')
		return (0);
	if (path->grid[y][x] == 'C')
		path->collects--;
	if (path->grid[y][x] == 'E')
	{
		path->exit_x = 1;
		return (0);
	}
	path->grid[y][x] = '1';
	if (check_path(path, y + 1, x) || check_path(path, y - 1, x))
		return (1);
	if (check_path(path, y, x + 1) || check_path(path, y, x - 1))
		return (1);
	return (0);
}

void	flood_fill(t_map	*map)
{
	t_map	copy;
	size_t	i;

	copy.height = map->height;
	copy.width = map->width;
	copy.collects = map->collects;
	copy.player_x = map->player_x;
	copy.player_y = map->player_y;
	copy.exit_x = 0;
	copy.grid = (char **)malloc(sizeof(char *) * copy.height);
	if (!copy.grid)
		error_msg("Memory allocation failed!");
	i = 0;
	while (i < copy.height)
	{
		copy.grid[i] = ft_strdup(map->grid[i]);
		if (!copy.grid[i])
			error_msg("Memory allocation failed!");
		i++;
	}
	check_path(&copy, copy.player_y, copy.player_x);
	if (copy.exit_x != 1 || copy.collects != 0)
		error_msg("There's no valid path");
	free_grid(copy.grid, copy.height);
}
