/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_set_type_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:55:20 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/29 16:32:37 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	north_set_type_path(t_main *main, char *current)
{
	if (ft_strncmp(current, "NO", 2) == 0)
	{
		if (main->map_data->north_texture != NULL)
		{
			errno = EINVAL;
			error_exit(main);
		}
		main->map_data->north_texture = copy_path(current + 2, main);
	}
}

void	east_set_type_path(t_main *main, char *current)
{
	if (ft_strncmp(current, "EA", 2) == 0)
	{
		if (main->map_data->east_texture != NULL)
		{
			errno = EINVAL;
			error_exit(main);
		}
		main->map_data->east_texture = copy_path(current + 2, main);
	}
}

void	south_set_type_path(t_main *main, char *current)
{
	if (ft_strncmp(current, "SO", 2) == 0)
	{
		if (main->map_data->south_texture != NULL)
		{
			errno = EINVAL;
			error_exit(main);
		}
		main->map_data->south_texture = copy_path(current + 2, main);
	}
}

void	west_set_type_path(t_main *main, char *current)
{
	if (ft_strncmp(current, "WE", 2) == 0)
	{
		if (main->map_data->west_texture != NULL)
		{
			errno = EINVAL;
			error_exit(main);
		}
		main->map_data->west_texture = copy_path(current + 2, main);
	}
}

