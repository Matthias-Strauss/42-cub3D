/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:56:40 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/04 16:25:39 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	free_map_data_struct(t_main *main)
{
	if (main != NULL && main->map_data != NULL)
	{
		save_free (main->map_data->north_texture);
		save_free (main->map_data->east_texture);
		save_free (main->map_data->south_texture);
		save_free (main->map_data->west_texture);
		free_matrix (main->map_data->map_layout);
		save_free (main->map_data);
		main->map_data = NULL;
	}
}

void	free_parser_struct(t_main *main)
{
	if (main != NULL && main->parser != NULL)
	{
		free_matrix (main->parser->map_copy_heap);
		save_free (main->parser->ceiling_color);
		save_free (main->parser->floor_color);
		save_free (main->parser);
		main->parser = NULL;
	}
}

void	free_structs(t_main *main)
{
	free_parser_struct(main);
	free_map_data_struct(main);
	save_free (main);
}
