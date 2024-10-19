/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_set_player_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:20:31 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/19 23:44:53 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_orientation(t_main *main)
{
	if (main->map_data->player_orientation == 'E')
		main->player->angle = 0;
	else if (main->map_data->player_orientation == 'S')
		main->player->angle = M_PI / 2;
	else if (main->map_data->player_orientation == 'W')
		main->player->angle = M_PI;
	else if (main->map_data->player_orientation == 'N')
		main->player->angle = M_PI * 3 / 2;
}

void	set_player_data(t_main *main)
{
	main->player->position.x = main->map_data->player_position.x * TILESIZE
		+ TILESIZE / 2;
	main->player->position.y = main->map_data->player_position.y * TILESIZE
		+ TILESIZE / 2;
	set_player_orientation(main);
	main->player->delta.x = cos(main->player->angle) * PLAYEROFFSET;
	main->player->delta.y = sin(main->player->angle) * PLAYEROFFSET;
	main->time = 0;
	main->fps = 0;
	main->tmpfps = 0;
}