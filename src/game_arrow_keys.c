/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_arrow_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:53:49 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/25 20:44:09 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	left_key(t_main *main)
{
	t_player	*p;
	float		tmp_dir_y;
	float		tmp_plane_y;

	p = main->player;
	if (mlx_is_key_down(main->mlx, MLX_KEY_LEFT))
	{
		tmp_dir_y = p->dir.y;
		p->dir.y = p->dir.y * p->cos_rot - p->dir.x
			* p->sin_rot;
		p->dir.x = tmp_dir_y * p->sin_rot + p->dir.x
			* p->cos_rot;
		tmp_plane_y = p->plane.y;
		p->plane.y = p->plane.y * p->cos_rot - p->plane.x
			* p->sin_rot;
		p->plane.x = tmp_plane_y * p->sin_rot + p->plane.x
			* p->cos_rot;
	}
}

void	right_key(t_main *main)
{
	t_player	*player;
	float		tmp_dir_x;
	float		tmp_plane_x;

	player = main->player;
	if (mlx_is_key_down(main->mlx, MLX_KEY_RIGHT))
	{
		tmp_dir_x = player->dir.x;
		player->dir.x = player->dir.x * player->cos_rot - player->dir.y
			* player->sin_rot;
		player->dir.y = tmp_dir_x * player->sin_rot + player->dir.y
			* player->cos_rot;
		tmp_plane_x = player->plane.x;
		player->plane.x = player->plane.x * player->cos_rot - player->plane.y
			* player->sin_rot;
		player->plane.y = tmp_plane_x * player->sin_rot + player->plane.y
			* player->cos_rot;
	}
}

void	arrow_up(t_main *main)
{
	if (mlx_is_key_down(main->mlx, MLX_KEY_UP))
	{
		if (main->player->pitch < MAX_PITCH)
			main->player->pitch += 20;
		else
			main->player->pitch = MAX_PITCH;
	}
}

void	arrow_down(t_main *main)
{
	if (mlx_is_key_down(main->mlx, MLX_KEY_DOWN))
	{
		if (main->player->pitch > -MAX_PITCH)
			main->player->pitch -= 20;
		else
			main->player->pitch = -MAX_PITCH;
	}
}

void	arrow_keys(t_main *main)
{
	left_key(main);
	right_key(main);
	arrow_up(main);
	arrow_down(main);
}
