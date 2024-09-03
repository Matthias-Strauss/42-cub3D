/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_set_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:55:20 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/03 16:34:18 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	if (main->parser->ceiling_color == NULL)
		return (false);
	if (main->parser->floor_color == NULL)
		return (false);
	return (true);
}

char	*get_type_pointer(t_main *main, char *id)
{
	if (ft_strncmp(id, "NO", 2) == 0)
		return (main->map_data->north_texture);
	if (ft_strncmp(id, "EA", 2) == 0)
		return (main->map_data->east_texture);
	if (ft_strncmp(id, "SO", 2) == 0)
		return (main->map_data->south_texture);
	if (ft_strncmp(id, "WE", 2) == 0)
		return (main->map_data->west_texture);
	if (ft_strncmp(id, "C", 1) == 0)
		return (main->parser->ceiling_color);
	if (ft_strncmp(id, "F", 1) == 0)
		return (main->parser->floor_color);
	return (NULL);
}

bool	is_already_set(t_main *main, char *id)
{
	if (ft_strncmp(id, "NO", 2) == 0)
		if (main->map_data->north_texture != NULL)
			return (true);
	if (ft_strncmp(id, "EA", 2) == 0)
		if (main->map_data->east_texture != NULL)
			return (true);
	if (ft_strncmp(id, "SO", 2) == 0)
		if (main->map_data->south_texture != NULL)
			return (true);
	if (ft_strncmp(id, "WE", 2) == 0)
		if (main->map_data->west_texture != NULL)
			return (true);
	if (ft_strncmp(id, "C", 1) == 0)
		if (main->parser->ceiling_color != NULL)
			return (true);
	if (ft_strncmp(id, "F", 1) == 0)
		if (main->parser->floor_color != NULL)
			return (true);
	return (false);
}

char	*set_type_path(char *id, char *current, t_main *main)
{
	int	id_len;
	int	skipped;

	id_len = ft_strlen(id);
	skipped = skip_whitespaces(current, 0);
	if (ft_strncmp(current + skipped, id, id_len) == 0)
	{
		if (is_already_set(main, id) == true)
			error_exit(main, ERR_TCR_C);
		return (copy_path(current + id_len + skipped, main));
	}
	return (get_type_pointer(main, id));
}

void	set_types(t_main *main)
{
	int		i;
	char	*current;

	i = 0;
	while (main->parser->map_copy_heap[i])
	{
		current = main->parser->map_copy_heap[i];
		main->map_data->north_texture = set_type_path("NO", current, main);
		main->map_data->east_texture = set_type_path("EA", current, main);
		main->map_data->south_texture = set_type_path("SO", current, main);
		main->map_data->west_texture = set_type_path("WE", current, main);
		main->parser->ceiling_color = set_type_path("C", current, main);
		main->parser->floor_color = set_type_path("F", current, main);
		if (main->parser->last_type_index == 0 && check_types(main) == true)
			main->parser->last_type_index = i;
		i++;
	}
	if (main->parser->last_type_index == 0)
		error_exit(main, ERR_TNS_C);
}
