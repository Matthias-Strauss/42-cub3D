/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:07 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/02 12:58:02 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_map(t_main *main)
{
	set_types(main);
	check_for_garbage(main);
	get_map_layout(main);
	check_map_layout(main);
	get_player_position(main->map_data);
	get_map_dimensions(main->map_data);
}
