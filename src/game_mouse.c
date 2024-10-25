/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:41:41 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/25 14:56:09 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_movement(t_main *main)
{
	int_fast32_t	x;
	int_fast32_t	y;
	int_fast32_t	delta_x;
	int_fast32_t	delta_y;
	float			rotation_speed;
	t_player		*player;
	float			old_plane_x;
	float			old_dir_x;
	float			pitch_speed;

	player = main->player;
	mlx_get_mouse_pos(main->mlx, &x, &y);
	delta_x = x - (main->mlx->width / 2);
	delta_y = y - (main->mlx->height / 2);
	rotation_speed = 0.003;
	if (delta_x != 0)
	{
		old_dir_x = player->dir.x;
		player->dir.x = player->dir.x * cos(delta_x * rotation_speed)
			- player->dir.y * sin(delta_x * rotation_speed);
		player->dir.y = old_dir_x * sin(delta_x * rotation_speed)
			+ player->dir.y * cos(delta_x * rotation_speed);
		old_plane_x = player->plane.x;
		player->plane.x = player->plane.x * cos(delta_x * rotation_speed)
			- player->plane.y * sin(delta_x * rotation_speed);
		player->plane.y = old_plane_x * sin(delta_x * rotation_speed)
			+ player->plane.y * cos(delta_x * rotation_speed);
	}
	pitch_speed = 0.5;
	player->pitch -= delta_y * pitch_speed;
	if (player->pitch > MAX_PITCH)
		player->pitch = MAX_PITCH;
	else if (player->pitch < -MAX_PITCH)
		player->pitch = -MAX_PITCH;
	mlx_set_mouse_pos(main->mlx, main->mlx->width / 2, main->mlx->height / 2);
}
