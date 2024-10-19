/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:07 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/19 15:07:48 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(t_main *main)
{
	set_types(main);
	convert_colors(main);
	check_for_garbage(main);
	get_map_layout(main);
	check_map_layout(main);
	get_player_position(main->map_data);
	get_map_dimensions(main->map_data);
}
