/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:07 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/01 14:09:47 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_player_position(t_map_data *map_data)
{
	int	y;
	int	x;

	y = 0;
	while (map_data->map_layout[y])
	{
		x = 0;
		while (map_data->map_layout[y][x])
		{
			if (map_data->map_layout[y][x] == map_data->player_orientation)
			{
				map_data->player_position.y = y;
				map_data->player_position.x = x;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	get_map_dimensions(t_map_data *map_data)
{
	int	y;
	int	x;
	int	longest;

	longest = 0;
	y = 0;
	while (map_data->map_layout[y])
	{
		x = 0;
		while (map_data->map_layout[y][x])
		{
			if (x > longest)
				longest = x;
			x++;
		}
		y++;
	}
	map_data->map_width = longest;
	map_data->map_height = y;
}

void	parse_map(t_main *main)
{
	set_types(main);
	get_map_layout(main);
	check_map_layout(main);
	get_player_position(main->map_data);
	get_map_dimensions(main->map_data);
}
