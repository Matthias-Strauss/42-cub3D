/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_wasd_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:44:12 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/20 20:35:30 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	w_key(t_main *main, t_point current, float dist_x, float dist_y)
{
	t_point	new;

	if (mlx_is_key_down(main->mlx, MLX_KEY_W))
	{
		new.x = (int)(main->player->position.x + dist_x) >> 6;
		new.y = (int)(main->player->position.y + dist_y) >> 6;
		if (main->map_data->map_coor[new.y][new.x] != '1'
			&& (main->map_data->map_coor[current.y][new.x] != '1'
				|| main->map_data->map_coor[new.y][current.x] != '1'))
		{
			main->player->position.y += dist_y;
			main->player->position.x += dist_x;
		}
	}
}

void	a_key(t_main *main, t_point current, float dist_x, float dist_y)
{
	t_point	new;

	if (mlx_is_key_down(main->mlx, MLX_KEY_A))
	{
		new.x = (int)(main->player->position.x + dist_y) >> 6;
		new.y = (int)(main->player->position.y - dist_x) >> 6;
		if (main->map_data->map_coor[new.y][new.x] != '1'
			&& (main->map_data->map_coor[current.y][new.x] != '1'
				|| main->map_data->map_coor[new.y][current.x] != '1'))
		{
			main->player->position.y -= dist_x;
			main->player->position.x += dist_y;
		}
	}
}

void	s_key(t_main *main, t_point current, float dist_x, float dist_y)
{
	t_point	new;

	if (mlx_is_key_down(main->mlx, MLX_KEY_S))
	{
		new.x = (int)(main->player->position.x - dist_x) >> 6;
		new.y = (int)(main->player->position.y - dist_y) >> 6;
		if (main->map_data->map_coor[new.y][new.x] != '1'
			&& (main->map_data->map_coor[current.y][new.x] != '1'
				|| main->map_data->map_coor[new.y][current.x] != '1'))
		{
			main->player->position.y -= dist_y;
			main->player->position.x -= dist_x;
		}
	}
}

void	d_key(t_main *main, t_point current, float dist_x, float dist_y)
{
	t_point	new;

	if (mlx_is_key_down(main->mlx, MLX_KEY_D))
	{
		new.x = (int)(main->player->position.x - dist_y) >> 6;
		new.y = (int)(main->player->position.y + dist_x) >> 6;
		if (main->map_data->map_coor[new.y][new.x] != '1'
			&& (main->map_data->map_coor[current.y][new.x] != '1'
				|| main->map_data->map_coor[new.y][current.x] != '1'))
		{
			main->player->position.y += dist_x;
			main->player->position.x -= dist_y;
		}
	}
}

void	wasd_keys(t_main *main)
{
	t_point	current_player_position;
	float	distance_x;
	float	distance_y;

	current_player_position.x = (int)(main->player->position.x) >> 6;
	current_player_position.y = (int)(main->player->position.y) >> 6;
	distance_y = main->player->direction.y * PLAYER_SPEED;
	distance_x = main->player->direction.x * PLAYER_SPEED;
	w_key(main, current_player_position, distance_x, distance_y);
	a_key(main, current_player_position, distance_x, distance_y);
	s_key(main, current_player_position, distance_x, distance_y);
	d_key(main, current_player_position, distance_x, distance_y);
}
