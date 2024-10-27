/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:46:37 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/27 13:38:32 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_orientation(t_main *main)
{
	if (main->map_data->player_orientation == 'N')
	{
		main->player->dir.x = 0;
		main->player->dir.y = -1;
	}
	else if (main->map_data->player_orientation == 'S')
	{
		main->player->dir.x = 0;
		main->player->dir.y = 1;
	}
	else if (main->map_data->player_orientation == 'E')
	{
		main->player->dir.x = 1;
		main->player->dir.y = 0;
	}
	else if (main->map_data->player_orientation == 'W')
	{
		main->player->dir.x = -1;
		main->player->dir.y = 0;
	}
}

void	set_player_data(t_main *main)
{
	set_player_orientation(main);
	main->player->plane.x = -main->player->dir.y * FOV;
	main->player->plane.y = main->player->dir.x * FOV;
	main->player->pos.x = main->map_data->player_pos.x + 1.0 / 2.0;
	main->player->pos.y = main->map_data->player_pos.y + 1.0 / 2.0;
	main->player->pitch = 100;
	main->player->speed = PLAYER_SPEED;
	main->time = 0;
	main->fps = 0;
	main->tmpfps = 0;
	main->player->height = 0;
	main->player->cos_rot = cos(ROTATION_SPEED);
	main->player->sin_rot = sin(ROTATION_SPEED);
}

void	set_toggles(t_main *main)
{
	main->texture_toggle_walls = false;
	main->texture_toggle_floor = false;
	main->mouse_toggle = false;
}

void	init_data(t_main *main)
{
	int32_t	width;
	int32_t	height;

	set_player_data(main);
	set_toggles(main);
	pre_calc_colors(main);
	main->frame = 0;
	mlx_set_setting(MLX_FULLSCREEN, false);
	main->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (main->mlx == NULL)
		error_exit(main, mlx_errno);
	mlx_get_monitor_size(0, &width, &height);
	mlx_set_window_size(main->mlx, width, height);
	main->image = mlx_new_image(main->mlx, main->mlx->width, main->mlx->height);
	init_background(main);
	main->minimap = mlx_new_image(main->mlx, main->mlx->width / MINIMAP_SIZE,
			main->mlx->height / MINIMAP_SIZE);
	main->minimap->enabled = false;
	// mlx_set_cursor_mode(main->mlx, MLX);
	// mlx_image_to_window(main->mlx, main->background, 0, 0);
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

void	end_game(t_main *main)
{
	mlx_delete_image(main->mlx, main->image);
	mlx_delete_image(main->mlx, main->background);
	mlx_delete_image(main->mlx, main->minimap);
	mlx_terminate(main->mlx);
}
