/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_arrow_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:53:49 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/20 20:58:30 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	left_key(t_main *main)
{
	t_player	*player;
	double		tmp_dir_x;
	double		tmp_plane_x;
	double		cos_rot;
	double		sin_rot;

	player = main->player;
	if (mlx_is_key_down(main->mlx, MLX_KEY_LEFT))
	{
		cos_rot = cos(ROTATION_SPEED);
		sin_rot = sin(ROTATION_SPEED);
		tmp_dir_x = player->direction.x;
		player->direction.x = player->direction.x * cos_rot
			- player->direction.y * sin_rot;
		player->direction.y = tmp_dir_x * sin_rot + player->direction.y
			* cos_rot;
		tmp_plane_x = player->plane.x;
		player->plane.x = player->plane.x * cos_rot - player->plane.y * sin_rot;
		player->plane.y = tmp_plane_x * sin_rot + player->plane.y * cos_rot;
	}
}

void	right_key(t_main *main)
{
	t_player	*player;
	double		tmp_dir_y;
	double		tmp_plane_y;
	double		cos_rot;
	double		sin_rot;

	player = main->player;
	if (mlx_is_key_down(main->mlx, MLX_KEY_LEFT))
	{
		cos_rot = cos(ROTATION_SPEED);
		sin_rot = sin(ROTATION_SPEED);
		tmp_dir_y = player->direction.y;
		player->direction.y = player->direction.y * cos_rot
			- player->direction.x * sin_rot;
		player->direction.x = tmp_dir_y * sin_rot + player->direction.x
			* cos_rot;
		tmp_plane_y = player->plane.y;
		player->plane.y = player->plane.y * cos_rot - player->plane.x * sin_rot;
		player->plane.x = tmp_plane_y * sin_rot + player->plane.x * cos_rot;
	}
}

void	arrow_keys(t_main *main)
{
	left_key(main);
	right_key(main);
}
