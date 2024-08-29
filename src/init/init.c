/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:59:22 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/29 19:40:13 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_parser_struct(t_main *main)
{
	main->parser = malloc(sizeof (t_parser) * 1);
	if (main->parser == NULL)
		error_exit(main, ERR_UAM_C);
	main->parser->map_copy_heap = NULL;
	main->parser->map_fd = 0;
	main->parser->map_path_stack = NULL;
}

void	init_map_data_struct(t_main *main)
{
	main->map_data = malloc(sizeof (t_map_data) * 1);
	if (main->map_data == NULL)
		error_exit(main, ERR_UAM_C);
	main->map_data->north_texture = NULL;
	main->map_data->east_texture = NULL;
	main->map_data->south_texture = NULL;
	main->map_data->west_texture = NULL;
	main->map_data->floor_color = NULL;
	main->map_data->ceiling_color = NULL;
	main->map_data->map_layout = NULL;
}

t_main	*init_main_struct(void)
{
	t_main	*main;

	main = malloc(sizeof (t_main) * 1);
	if (main == NULL)
		error_exit(main, ERR_UAM_C);
	main->parser = NULL;
	main->map_data = NULL;
	return (main);
}

t_main	*init_structs(void)
{
	t_main	*main;

	main = init_main_struct();
	init_parser_struct(main);
	init_map_data_struct(main);
	return (main);
}
