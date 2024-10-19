/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:36:42 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/19 23:44:37 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	escape(t_main *main)
{
	if (mlx_is_key_down(main->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(main->mlx);
}

bool	wallcheck(char *id, t_main *main)
{
	int		x;
	int		y;
	float	distance_x;
	float	distance_y;

	distance_x = main->player->delta.x * PLAYER_SPEED;
	distance_y = main->player->delta.y * PLAYER_SPEED;

	if (ft_strncmp("UP", id, 2) == 0)
	{
		x = (int)(main->player->position.x + distance_x) >> 6;
		y = (int)(main->player->position.y + distance_y) >> 6;
		if (main->map_data->map_layout[y][x] == '1')
			return (true);
	}
	if (ft_strncmp("DOWN", id, 4) == 0)
	{
		x = (int)(main->player->position.x - distance_x) >> 6;
		y = (int)(main->player->position.y - distance_y) >> 6;
		if (main->map_data->map_layout[y][x] == '1')
			return (true);
	}
	if (ft_strncmp("A", id, 1) == 0)
	{
		x = (int)(main->player->position.x + distance_y) >> 6;
		y = (int)(main->player->position.y - distance_x) >> 6;
		if (main->map_data->map_layout[y][x] == '1')
			return (true);
	}
	if (ft_strncmp("D", id, 1) == 0)
	{
		x = (int)(main->player->position.x - distance_y) >> 6;
		y = (int)(main->player->position.y + distance_x) >> 6;
		if (main->map_data->map_layout[y][x] == '1')
			return (true);
	}
	return (false);
}

void	movement(t_main *main)
{
	if (mlx_is_key_down(main->mlx, MLX_KEY_W))
	{
		if (wallcheck("UP", main) == false)
		{
			main->player->position.y += main->player->delta.y * PLAYER_SPEED;
			main->player->position.x += main->player->delta.x * PLAYER_SPEED;
		}
	}
	if (mlx_is_key_down(main->mlx, MLX_KEY_S))
	{
		if (wallcheck("DOWN", main) == false)
		{
			main->player->position.y -= main->player->delta.y * PLAYER_SPEED;
			main->player->position.x -= main->player->delta.x * PLAYER_SPEED;
		}
	}
	if (mlx_is_key_down(main->mlx, MLX_KEY_A))
	{
		if (wallcheck("A", main) == false)
		{
			main->player->position.x += main->player->delta.y * PLAYER_SPEED;
			main->player->position.y -= main->player->delta.x * PLAYER_SPEED;
		}
	}
	if (mlx_is_key_down(main->mlx, MLX_KEY_D))
	{
		if (wallcheck("D", main) == false)
		{
			main->player->position.x -= main->player->delta.y * PLAYER_SPEED;
			main->player->position.y += main->player->delta.x * PLAYER_SPEED;
		}
	}
	if (mlx_is_key_down(main->mlx, MLX_KEY_LEFT))
	{
		main->player->angle -= 0.1;
		if (main->player->angle < 0)
			main->player->angle += 2 * M_PI;
		main->player->delta.x = cos(main->player->angle) * PLAYEROFFSET;
		main->player->delta.y = sin(main->player->angle) * PLAYEROFFSET;
	}
	if (mlx_is_key_down(main->mlx, MLX_KEY_RIGHT))
	{
		main->player->angle += 0.1;
		if (main->player->angle > 2 * M_PI)
			main->player->angle -= 2 * M_PI;
		main->player->delta.x = cos(main->player->angle) * PLAYEROFFSET;
		main->player->delta.y = sin(main->player->angle) * PLAYEROFFSET;
	}
}

void	key_hooks(void *main)
{
	escape((t_main *)main);
	movement((t_main *)main);
}
