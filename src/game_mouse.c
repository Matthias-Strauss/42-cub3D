/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:41:41 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/28 12:54:06 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	handle_mouse_x(t_point *delta, t_player *player)
{
	float	cos_val;
	float	sin_val;
	float	old_dir_x;
	float	old_plane_x;

	cos_val = cosf(delta->x * MOUSE_ROT_SPEED);
	sin_val = sinf(delta->x * MOUSE_ROT_SPEED);
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos_val - player->dir.y * sin_val;
	player->dir.y = old_dir_x * sin_val + player->dir.y * cos_val;
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x * cos_val - player->plane.y * sin_val;
	player->plane.y = old_plane_x * sin_val + player->plane.y * cos_val;
}

void	mouse_movement(t_main *main)
{
	t_point		mouse_pos;
	t_point		delta;
	t_player	*player;

	player = main->player;
	mlx_get_mouse_pos(main->mlx, &mouse_pos.x, &mouse_pos.y);
	delta.x = mouse_pos.x - (main->mlx->width / 2);
	delta.y = mouse_pos.y - (main->mlx->height / 2);
	if (delta.x != 0)
		handle_mouse_x(&delta, player);
	player->pitch -= delta.y * MOUSE_PITCH_SPEED;
	if (player->pitch > MAX_PITCH)
		player->pitch = MAX_PITCH;
	else if (player->pitch < -MAX_PITCH)
		player->pitch = -MAX_PITCH;
	mlx_set_mouse_pos(main->mlx, main->mlx->width / 2, main->mlx->height / 2);
}
