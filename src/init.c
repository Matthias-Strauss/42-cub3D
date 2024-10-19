/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:59:22 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/19 23:38:55 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parser_struct(t_main *main)
{
	main->parser = malloc(sizeof(t_parser) * 1);
	if (main->parser == NULL)
		error_exit(main, ERR_UAM);
	main->parser->map_copy_heap = NULL;
	main->parser->map_fd = 0;
	main->parser->map_path_stack = NULL;
	main->parser->last_type_index = 0;
	main->parser->floor_color = NULL;
	main->parser->ceiling_color = NULL;
}

void	init_map_data_struct(t_main *main)
{
	main->map_data = malloc(sizeof(t_map_data) * 1);
	if (main->map_data == NULL)
		error_exit(main, ERR_UAM);
	main->map_data->north_texture = NULL;
	main->map_data->east_texture = NULL;
	main->map_data->south_texture = NULL;
	main->map_data->west_texture = NULL;
	main->map_data->map_coor = NULL;
	main->map_data->player_orientation = '\1';
}

void	init_player_struct(t_main *main)
{
	main->player = malloc(sizeof(t_player) * 1);
	if (main->player == NULL)
		error_exit(main, ERR_UAM);
	main->player->position.x = 0;
	main->player->position.y = 0;
	main->player->pitch = 100;
	main->player->speed = 1;
}

t_main	*init_main_struct(void)
{
	t_main	*main;

	main = malloc(sizeof(t_main) * 1);
	if (main == NULL)
		error_exit(main, ERR_UAM);
	main->parser = NULL;
	main->map_data = NULL;
	main->player = NULL;
	main->mlx = NULL;
	main->image = NULL;
	return (main);
}

t_main	*init_structs(void)
{
	t_main	*main;

	main = init_main_struct();
	init_parser_struct(main);
	init_map_data_struct(main);
	init_player_struct(main);
	return (main);
}
