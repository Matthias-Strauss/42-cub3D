/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:56:40 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/29 18:21:35 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	save_free(void *to_free)
{
	if (to_free != NULL)
		free (to_free);
}

void	free_matrix(char **to_free)
{
	int	i;

	i = 0;
	if (to_free != NULL)
	{
		while (to_free[i] != NULL)
		{
			save_free (to_free[i]);
			i++;
		}
		save_free (to_free);
	}
}

void	free_structs(t_main *main)
{
	if (main->parser != NULL)
	{
		free_matrix (main->parser->map_copy_heap);
		save_free (main->parser);
	}
	if (main->map_data != NULL)
	{
		save_free (main->map_data->north_texture);
		save_free (main->map_data->east_texture);
		save_free (main->map_data->south_texture);
		save_free (main->map_data->west_texture);
		save_free (main->map_data->ceiling_color);
		save_free (main->map_data->floor_color);
		save_free (main->map_data);
	}
	if (main != NULL)
		save_free (main);
}
