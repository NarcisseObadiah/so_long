/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:19:04 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/15 20:00:47 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

size_t	count_row(char **grid)
{
	size_t	y;

	y = 0;
	while (grid[y])
		y++;
	return (y);
}

size_t	count_collects(t_map *map)
{
	int	x;
	int	y;
	int	nbr_collect;

	y = 0;
	nbr_collect = 0;
	while (y < (int)map->height)
	{
		x = 0;
		while (x < (int)map->width)
		{
			if (map->grid[y][x] == 'C')
				nbr_collect++;
			x++;
		}
		y++;
	}
	return (nbr_collect);
}

char	*read_map(char *map)
{
	char	*line;
	char	*joined;
	char	*temp;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	joined = ft_strdup(line);
	while (line)
	{
		temp = ft_strjoin(joined, line);
		free(joined);
		joined = temp;
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	return (joined);
}
