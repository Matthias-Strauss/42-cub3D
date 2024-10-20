/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_wasd_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:44:12 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/20 03:54:24 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	w_key(t_main *main)
{
	t_point_int	current;
	t_point_int	new;
	float	distance_x;
	float	distance_y;

	if (mlx_is_key_down(main->mlx, MLX_KEY_W))
	{
		distance_y = main->player->delta.y * PLAYER_SPEED;
		distance_x = main->player->delta.x * PLAYER_SPEED;
		current.x = (int)(main->player->position.x) >> 6;
		current.y = (int)(main->player->position.y) >> 6;
		new.x = (int)(main->player->position.x + distance_x) >> 6;
		new.y = (int)(main->player->position.y + distance_y) >> 6;
		if (main->map_data->map_layout[new.y][new.x] != '1' &&
			(main->map_data->map_layout[current.y][new.x] != '1'
			|| main->map_data->map_layout[new.y][current.x] != '1'))
		{
			main->player->position.y += distance_y;
			main->player->position.x += distance_x;
		}
	}
}

void	a_key(t_main *main)
{
	t_point_int	current;
	t_point_int	new;
	float		distance_x;
	float		distance_y;

	if (mlx_is_key_down(main->mlx, MLX_KEY_A))
	{
		distance_y = main->player->delta.y * PLAYER_SPEED;
		distance_x = main->player->delta.x * PLAYER_SPEED;
		current.x = (int)(main->player->position.x) >> 6;
		current.y = (int)(main->player->position.y) >> 6;
		new.x = (int)(main->player->position.x + distance_y) >> 6;
		new.y = (int)(main->player->position.y - distance_x) >> 6;
		if (main->map_data->map_layout[new.y][new.x] != '1' &&
			(main->map_data->map_layout[current.y][new.x] != '1'
			|| main->map_data->map_layout[new.y][current.x] != '1'))
		{
			main->player->position.y -= distance_x;
			main->player->position.x += distance_y;
		}
	}
}

void	s_key(t_main *main)
{
	t_point_int	current;
	t_point_int	new;
	float	distance_x;
	float	distance_y;

	if (mlx_is_key_down(main->mlx, MLX_KEY_S))
	{
		distance_y = main->player->delta.y * PLAYER_SPEED;
		distance_x = main->player->delta.x * PLAYER_SPEED;
		current.x = (int)(main->player->position.x) >> 6;
		current.y = (int)(main->player->position.y) >> 6;
		new.x = (int)(main->player->position.x - distance_x) >> 6;
		new.y = (int)(main->player->position.y - distance_y) >> 6;
		if (main->map_data->map_layout[new.y][new.x] != '1' &&
			(main->map_data->map_layout[current.y][new.x] != '1'
			|| main->map_data->map_layout[new.y][current.x] != '1'))
		{
			main->player->position.y -= distance_y;
			main->player->position.x -= distance_x;
		}
	}
}

void	d_key(t_main *main)
{
	t_point_int	current;
	t_point_int	new;
	float	distance_x;
	float	distance_y;

	if (mlx_is_key_down(main->mlx, MLX_KEY_D))
	{
		distance_y = main->player->delta.y * PLAYER_SPEED;
		distance_x = main->player->delta.x * PLAYER_SPEED;
		current.x = (int)(main->player->position.x) >> 6;
		current.y = (int)(main->player->position.y) >> 6;
		new.x = (int)(main->player->position.x - distance_y) >> 6;
		new.y = (int)(main->player->position.y + distance_x) >> 6;
		if (main->map_data->map_layout[new.y][new.x] != '1' &&
			(main->map_data->map_layout[current.y][new.x] != '1'
			|| main->map_data->map_layout[new.y][current.x] != '1'))
		{
			main->player->position.y += distance_x;
			main->player->position.x -= distance_y;
		}
	}
}

void	wasd_keys(t_main *main)
{
	w_key(main);
	a_key(main);
	s_key(main);
	d_key(main);
}
