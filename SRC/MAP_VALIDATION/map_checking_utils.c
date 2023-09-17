/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:24:35 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/08 15:15:03 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/*
- Checking for invalid content
- Checking for map content
- Checking for file extension
- Checking for map shape*/

void	check_invalid_content(int i)
{
	char	*elmt;

	elmt = "PCE01X\n";
	if (!(ft_strchr(elmt, i)))
		error_msg("Map contains invalid characters");
}

void	check_map_content(char *map)
{
	int	player;
	int	collect;
	int	exit;
	int	i;

	player = 0;
	collect = 0;
	exit = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			player++;
		else if (map[i] == 'C')
			collect++;
		else if (map[i] == 'E')
			exit++;
		else
			check_invalid_content(map[i]);
		i++;
	}
	if (player != 1 || exit != 1 || collect < 1)
		error_msg("Map contains is invalid");
}

void	check_map_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (!(len >= 4 && ft_strncmp(&file[len - 4], ".ber", 4) == 0))
		error_msg("Wrong file extension!!!");
}

void	check_map_shape(char **grid)
{	
	size_t	i;
	size_t	len_first_row;

	i = 0;
	len_first_row = ft_strlen(grid[i]);
	while (grid[i])
	{
		if (ft_strlen(grid[i]) != len_first_row)
		{
			error_msg("This map is not a rectangle!");
			break ;
		}
		i++;
	}
}

void	check_map_is_empty(char *map)
{
	if (!map[0])
		error_msg("The map is empty!");
}
