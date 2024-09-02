/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_set_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:55:20 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/02 11:34:53 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*set_type_path(char *id, char *current, t_main *main)
{
	int	id_len;
	int	skipped;

	id_len = ft_strlen(id);
	skipped = skip_whitespaces(current, 0);
	if (ft_strncmp(current + skipped, id, id_len) == 0)
	{
		return (copy_path(current + id_len + skipped, main));
	}
	return (NULL);
}

bool	check_types(t_main *main)
{
	if (main->map_data->north_texture == NULL)
		return (false);
	if (main->map_data->east_texture == NULL)
		return (false);
	if (main->map_data->south_texture == NULL)
		return (false);
	if (main->map_data->west_texture == NULL)
		return (false);
	if (main->map_data->ceiling_color == NULL)
		return (false);
	if (main->map_data->floor_color == NULL)
		return (false);
	return (true);
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
		if (main->parser->last_type_index == 0 && check_types(main) == true)
			main->parser->last_type_index = i;
		i++;
	}
	if (main->parser->last_type_index == 0)
		error_exit(main, ERR_TNS_C);
}
