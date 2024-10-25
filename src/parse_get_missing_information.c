/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_missing_information.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:19:17 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/24 18:40:59 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player_pos(t_map_data *map_data)
{
	int_fast32_t	y;
	int_fast32_t	x;

	y = 0;
	while (map_data->map_coor[y])
	{
		x = 0;
		while (map_data->map_coor[y][x])
		{
			if (map_data->map_coor[y][x] == map_data->player_orientation)
			{
				map_data->player_pos.y = y;
				map_data->player_pos.x = x;
				map_data->map_coor[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	get_map_dimensions(t_map_data *map_data)
{
	int_fast32_t	y;
	int_fast32_t	x;
	int_fast32_t	longest;

	longest = 0;
	y = 0;
	while (map_data->map_coor[y])
	{
		x = ft_strlen(map_data->map_coor[y]);
		if (longest < x)
			longest = x;
		y++;
	}
	map_data->map_width = longest;
	map_data->map_height = y;
}
