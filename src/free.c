/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:56:40 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/23 19:01:35 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map_data_struct(t_main *main)
{
	if (main != NULL && main->map_data != NULL)
	{
		safe_free(main->map_data->north_texture);
		safe_free(main->map_data->east_texture);
		safe_free(main->map_data->south_texture);
		safe_free(main->map_data->west_texture);
		free_matrix(main->map_data->map_coor);
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
		main->player = NULL;
	}
}

void	free_textures(t_main *main)
{
	int	i;

	i = 0;
	while (main->textures[i])
	{
		mlx_delete_texture(main->textures[i]);
		i++;
	}
}

void	free_structs(t_main *main)
{
	free_parser_struct(main);
	free_map_data_struct(main);
	free_player_struct(main);
	free_textures(main);
	safe_free(main);
}
