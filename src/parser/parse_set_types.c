/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_set_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:55:20 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/29 18:10:29 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*set_type_path(char *id, char *current, t_main *main)
{
	if (ft_strncmp(current, id, ft_strlen(id)) == 0)
	{
		return(copy_path(current + ft_strlen(id), main));
	}
	return (NULL);
}

void	set_types(t_main *main)
{
	int		i;
	char	*current;

	i = 0;
	while (main->parser->map_copy_heap[i])
	{
		current = main->parser->map_copy_heap[i];
		if (main->map_data->north_texture == NULL)
			main->map_data->north_texture = set_type_path("NO", current, main);
		if (main->map_data->east_texture == NULL)
			main->map_data->east_texture = set_type_path("EA", current, main);
		if (main->map_data->south_texture == NULL)
			main->map_data->south_texture = set_type_path("SO", current, main);
		if (main->map_data->west_texture == NULL)
			main->map_data->west_texture = set_type_path("WE", current, main);
		if (main->map_data->ceiling_color == NULL)
			main->map_data->ceiling_color = set_type_path("C", current, main);
		if (main->map_data->floor_color == NULL)
			main->map_data->floor_color = set_type_path("F", current, main);
		i++;
	}
}
