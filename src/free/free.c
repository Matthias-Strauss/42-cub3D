/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:56:40 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/10 13:33:30 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	safe_free(void *to_free)
{
	if (to_free != NULL) // @kai: what does this do? :P
		free(to_free);
}

void	free_matrix(char **to_free)
{
	int	i;

	i = 0;
	if (to_free != NULL)
	{
		while (to_free[i] != NULL)
		{
			safe_free(to_free[i]);
			i++;
		}
		safe_free(to_free);
	}
}

void	free_map_data_struct(t_main *main)
{
	if (main != NULL && main->map_data != NULL)
	{
		safe_free(main->map_data->north_texture);
		safe_free(main->map_data->east_texture);
		safe_free(main->map_data->south_texture);
		safe_free(main->map_data->west_texture);
		free_matrix(main->map_data->map_layout);
		safe_free(main->map_data);
		main->map_data = NULL;
	}
}

void	free_parser_struct(t_main *main)
{
	if (main != NULL && main->parser != NULL)
	{
		free_matrix(main->parser->map_copy_heap);
		safe_free(main->parser->ceiling_color);
		safe_free(main->parser->floor_color);
		safe_free(main->parser);
		main->parser = NULL;
	}
}

void	free_player_struct(t_main *main)
{
	if (main != NULL && main->player != NULL)
	{
		safe_free(main->player);
		main->parser = NULL;
	}
}

void	free_structs(t_main *main)
{
	free_parser_struct(main);
	free_map_data_struct(main);
	free_player_struct(main);
	safe_free(main);
}
