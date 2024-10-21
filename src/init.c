/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:59:22 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/21 15:25:04 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parser_struct(t_main *main)
{
	main->parser = calloc(sizeof(t_parser), 1);
	if (main->parser == NULL)
		error_exit(main, ERR_UAM);
}

void	init_map_data_struct(t_main *main)
{
	main->map_data = calloc(sizeof(t_map_data), 1);
	if (main->map_data == NULL)
		error_exit(main, ERR_UAM);
	main->map_data->player_orientation = '\1';
}

void	init_player_struct(t_main *main)
{
	main->player = calloc(sizeof(t_player), 1);
	if (main->player == NULL)
		error_exit(main, ERR_UAM);
	main->player->pitch = 100;
	main->player->speed = 1;
}

t_main	*init_main_struct(void)
{
	t_main	*main;

	main = calloc(sizeof(t_main), 1);
	if (main == NULL)
		error_exit(main, ERR_UAM);
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
