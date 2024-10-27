/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:41:41 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/27 21:48:35 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_movement(t_main *main)
{
	int_fast32_t	x;
	int_fast32_t	y;
	int_fast32_t	delta_x;
	int_fast32_t	delta_y;
	t_player		*player;
	float			old_plane_x;
	float			old_dir_x;
	float			cos_val;
	float			sin_val;

	player = main->player;
	mlx_get_mouse_pos(main->mlx, &x, &y);
	delta_x = x - (main->mlx->width / 2);
	delta_y = y - (main->mlx->height / 2);
	if (delta_x != 0)
	{
		cos_val = cosf(delta_x * MOUSE_ROT_SPEED);
		sin_val = sinf(delta_x * MOUSE_ROT_SPEED);
		old_dir_x = player->dir.x;
		player->dir.x = player->dir.x * cos_val - player->dir.y * sin_val;
		player->dir.y = old_dir_x * sin_val + player->dir.y * cos_val;
		old_plane_x = player->plane.x;
		player->plane.x = player->plane.x * cos_val - player->plane.y * sin_val;
		player->plane.y = old_plane_x * sin_val + player->plane.y * cos_val;
	}
	player->pitch -= delta_y * MOUSE_PITCH_SPEED;
	if (player->pitch > MAX_PITCH)
		player->pitch = MAX_PITCH;
	else if (player->pitch < -MAX_PITCH)
		player->pitch = -MAX_PITCH;
	mlx_set_mouse_pos(main->mlx, main->mlx->width / 2, main->mlx->height / 2);
}
