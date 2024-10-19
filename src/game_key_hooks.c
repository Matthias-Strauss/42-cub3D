/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:36:42 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/19 22:35:21 by mstrauss         ###   ########.fr       */
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
	int	x;
	int	y;

	if (ft_strncmp("UP", id, 2) == 0)
	{
		x = (int)(main->player->position.x + main->player->delta.x * 2) >> 6;
		y = (int)(main->player->position.y + main->player->delta.y * 2) >> 6;
		if (main->map_data->map_coor[y][x] == '1')
			return (true);
	}
	if (ft_strncmp("DOWN", id, 4) == 0)
	{
		x = (int)(main->player->position.x - main->player->delta.x * 2) >> 6;
		y = (int)(main->player->position.y - main->player->delta.y * 2) >> 6;
		if (main->map_data->map_coor[y][x] == '1')
			return (true);
	}
	return (false);
}

void	movement(t_main *main)
{
	if (mlx_is_key_down(main->mlx, MLX_KEY_UP))
	{
		if (wallcheck("UP", main) == false)
		{
			main->player->position.y += main->player->delta.y * PLAYER_SPEED;
			main->player->position.x += main->player->delta.x * PLAYER_SPEED;
		}
	}
	if (mlx_is_key_down(main->mlx, MLX_KEY_DOWN))
	{
		if (wallcheck("DOWN", main) == false)
		{
			main->player->position.y -= main->player->delta.y * PLAYER_SPEED;
			main->player->position.x -= main->player->delta.x * PLAYER_SPEED;
		}
	}
	if (mlx_is_key_down(main->mlx, MLX_KEY_LEFT))
	{
		main->player->angle -= 0.1;
		if (main->player->angle < 0)
			main->player->angle += 2 * M_PI;
		main->player->delta.x = cos(main->player->angle) * ANGLEOFFSET;
		main->player->delta.y = sin(main->player->angle) * ANGLEOFFSET;
	}
	if (mlx_is_key_down(main->mlx, MLX_KEY_RIGHT))
	{
		main->player->angle += 0.1;
		if (main->player->angle > 2 * M_PI)
			main->player->angle -= 2 * M_PI;
		main->player->delta.x = cos(main->player->angle) * ANGLEOFFSET;
		main->player->delta.y = sin(main->player->angle) * ANGLEOFFSET;
	}
}

void	key_hooks(void *main)
{
	escape((t_main *)main);
	movement((t_main *)main);
}
