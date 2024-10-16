/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:36:42 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/15 16:02:56 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	escape(mlx_key_data_t keydata, t_main *main)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(main->mlx);
}

bool	wallcheck(char *id, t_main *main)
{
	int	x;
	int	y;

	if (ft_strncmp("UP", id, 2) == 0)
	{
		x = (int)(main->player->position.x + main->player->delta.x) >> 6;
		y = (int)(main->player->position.y + main->player->delta.y) >> 6;
		if (main->map_data->map_layout[y][x] == '1')
			return (true);
	}
	if (ft_strncmp("DOWN", id, 4) == 0)
	{
		x = (int)(main->player->position.x - main->player->delta.x) >> 6;
		y = (int)(main->player->position.y - main->player->delta.y) >> 6;
		if (main->map_data->map_layout[y][x] == '1')
			return (true);
	}
	return (false);
}

void	movement(mlx_key_data_t keydata, t_main *main)
{
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
	{
		if (wallcheck("UP", main) == false)
		{
			main->player->position.y += main->player->delta.y * PLAYER_SPEED;
			main->player->position.x += main->player->delta.x * PLAYER_SPEED;
		}
	}
	{
		if (wallcheck("UP", main) == false)
		{
			main->player->position.y += main->player->delta.y * PLAYER_SPEED;
			main->player->position.x += main->player->delta.x * PLAYER_SPEED;
		}
	}
	if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
	{
		if (wallcheck("DOWN", main) == false)
		{
			main->player->position.y -= main->player->delta.y * PLAYER_SPEED;
			main->player->position.x -= main->player->delta.x * PLAYER_SPEED;
		}
	}
	{
		if (wallcheck("DOWN", main) == false)
		{
			main->player->position.y -= main->player->delta.y * PLAYER_SPEED;
			main->player->position.x -= main->player->delta.x * PLAYER_SPEED;
		}
	}
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{
		main->player->angle -= 0.1;
		if (main->player->angle < 0)
			main->player->angle += 2 * M_PI;
		main->player->delta.x = cos(main->player->angle) * ANGLEOFFSET;
		main->player->delta.y = sin(main->player->angle) * ANGLEOFFSET;
	}
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		main->player->angle += 0.1;
		if (main->player->angle > 2 * M_PI)
			main->player->angle -= 2 * M_PI;
		main->player->delta.x = cos(main->player->angle) * ANGLEOFFSET;
		main->player->delta.y = sin(main->player->angle) * ANGLEOFFSET;
	}
}

void	key_hooks(mlx_key_data_t keydata, void *main)
{
	escape(keydata, (t_main *)main);
	movement(keydata, (t_main *)main);
}
