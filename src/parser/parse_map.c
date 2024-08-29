/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:07 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/29 19:48:08 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_types(t_main *main)
{
	if (main->map_data->north_texture == NULL)
		error_exit(main, ERR_TNS_C);
	if (main->map_data->east_texture == NULL)
		error_exit(main, ERR_TNS_C);
	if (main->map_data->south_texture == NULL)
		error_exit(main, ERR_TNS_C);
	if (main->map_data->west_texture == NULL)
		error_exit(main, ERR_TNS_C);
	if (main->map_data->ceiling_color == NULL)
		error_exit(main, ERR_TNS_C);
	if (main->map_data->floor_color == NULL)
		error_exit(main, ERR_TNS_C);
}

void	parse_map(t_main *main)
{
	set_types(main);
	check_types(main);
}
