/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_arrow_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:53:49 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/22 21:40:36 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	left_key(t_main *main)
{
	t_player	*player;
	double		tmp_dir_y;
	double		tmp_plane_y;

	player = main->player;
	if (mlx_is_key_down(main->mlx, MLX_KEY_LEFT))
	{
		tmp_dir_y = player->dir.y;
		player->dir.y = player->dir.y * player->cos_rot - player->dir.x * player->sin_rot;
		player->dir.x = tmp_dir_y * player->sin_rot + player->dir.x * player->cos_rot;
		tmp_plane_y = player->plane.y;
		player->plane.y = player->plane.y * player->cos_rot - player->plane.x * player->sin_rot;
		player->plane.x = tmp_plane_y * player->sin_rot + player->plane.x * player->cos_rot;
	}
}

void	right_key(t_main *main)
{
	t_player	*player;
	double		tmp_dir_x;
	double		tmp_plane_x;

	player = main->player;
	if (mlx_is_key_down(main->mlx, MLX_KEY_RIGHT))
	{
		tmp_dir_x = player->dir.x;
		player->dir.x = player->dir.x * player->cos_rot - player->dir.y * player->sin_rot;
		player->dir.y = tmp_dir_x * player->sin_rot + player->dir.y * player->cos_rot;
		tmp_plane_x = player->plane.x;
		player->plane.x = player->plane.x * player->cos_rot - player->plane.y * player->sin_rot;
		player->plane.y = tmp_plane_x * player->sin_rot + player->plane.y * player->cos_rot;
	}
}

void	arrow_keys(t_main *main)
{
	left_key(main);
	right_key(main);
}
