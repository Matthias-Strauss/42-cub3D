/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:07 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/29 16:58:05 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ceiling_set_color(t_main *main, char *current)
{
	if (ft_strncmp(current, "C", 1) == 0)
	{
		if (main->map_data->ceiling_color != NULL)
		{
			errno = EINVAL;
			error_exit(main);
		}
		main->map_data->ceiling_color = copy_path(current + 1, main);
	}
}

void	floor_set_color(t_main *main, char *current)
{
	if (ft_strncmp(current, "F", 1) == 0)
	{
		if (main->map_data->ceiling_color != NULL)
		{
			errno = EINVAL;
			error_exit(main);
		}
		main->map_data->floor_color = copy_path(current + 1, main);
	}
}

void	set_types(t_main *main)
{
	int		i;
	char	*current;

	i = 0;
	while (main->parser->map_copy_heap[i])
	{
		current = main->parser->map_copy_heap[i];
		north_set_type_path(main, current);
		east_set_type_path(main, current);
		south_set_type_path(main, current);
		west_set_type_path(main, current);
		ceiling_set_color(main, current);
		floor_set_color(main, current);
		i++;
	}
}

void	parse_map(t_main *main)
{
	set_types(main);
	check_types(main);
	// get_map_content()
}
