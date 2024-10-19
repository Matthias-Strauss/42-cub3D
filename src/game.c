/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:46:37 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/19 15:59:13 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_data(t_main *main)
{
	main->player->position.x = main->map_data->player_position.x * TILESIZE
		+ TILESIZE / 2;
	main->player->position.y = main->map_data->player_position.y * TILESIZE
		+ TILESIZE / 2;
	main->player->angle = 0;
	main->player->delta.x = cos(main->player->angle) * ANGLEOFFSET;
	main->player->delta.y = sin(main->player->angle) * ANGLEOFFSET;
	main->time = 0;
	main->fps = 0;
	main->tmpfps = 0;
}

void	start_game(t_main *main)
{
	int32_t	width;
	int32_t	height;

	set_player_data(main);
	mlx_set_setting(MLX_FULLSCREEN, true);
	main->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (main->mlx == NULL)
		error_exit(main, mlx_errno);
	mlx_get_monitor_size(0, &width, &height);
	mlx_set_window_size(main->mlx, width, height);
	main->image = mlx_new_image(main->mlx, main->mlx->width, main->mlx->height);
	main->background = mlx_new_image(main->mlx, main->mlx->width,
			main->mlx->height);
	init_background(main);
	main->minimap = mlx_new_image(main->mlx, main->mlx->width / MINIMAP_SIZE,
			main->mlx->height / MINIMAP_SIZE);
	mlx_image_to_window(main->mlx, main->background, 0, 0);
	mlx_image_to_window(main->mlx, main->image, 0, 0);
	mlx_image_to_window(main->mlx, main->minimap, main->mlx->width * 0.01,
		main->mlx->height * 0.01);
	mlx_focus(main->mlx);
}

void	fps(void *param)
{
	t_main	*main;

	main = param;
	if (main->time <= 1)
	{
		main->time += main->mlx->delta_time;
		main->tmpfps++;
	}
	else
	{
		main->fps = main->tmpfps;
		printf("FPS: [%f]\n", main->fps);
		main->time = 0;
		main->tmpfps = 0;
	}
}

void	during_game(t_main *main)
{
	mlx_loop_hook(main->mlx, fps, main);
	mlx_loop_hook(main->mlx, key_hooks, main);
	mlx_loop_hook(main->mlx, loop_hooks, main);
	mlx_loop(main->mlx);
}

void	end_game(t_main *main)
{
	mlx_delete_image(main->mlx, main->image);
	mlx_delete_image(main->mlx, main->background);
	mlx_delete_image(main->mlx, main->minimap);
	mlx_terminate(main->mlx);
}
