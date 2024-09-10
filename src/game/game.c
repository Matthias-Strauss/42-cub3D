/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:46:37 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/10 23:59:25 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_player_data(t_main *main)
{
	main->player->position.x = main->map_data->player_position.x * TILESIZE + TILESIZE / 2;
	main->player->position.y = main->map_data->player_position.y * TILESIZE + TILESIZE / 2;
	main->player->angle = M_PI + M_PI / 2;
	// main->player->angle = 0;
	main->player->delta.x = cos(main->player->angle) * ANGLEOFFSET;
	main->player->delta.y = sin(main->player->angle) * ANGLEOFFSET;
}

void	start_game(t_main *main)
{
	set_player_data(main);
	main->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (main->mlx == NULL)
		error_exit(main, mlx_errno);
}

void	during_game(t_main *main)
{
	mlx_loop_hook(main->mlx, loop_hooks, main);
	mlx_key_hook(main->mlx, key_hooks, main);
	mlx_loop(main->mlx);
}

void	end_game(t_main *main)
{
	mlx_terminate(main->mlx);
}
