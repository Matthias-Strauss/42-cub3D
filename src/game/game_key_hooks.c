/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:36:42 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/12 18:13:38 by kklockow         ###   ########.fr       */
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
	if (keydata.key == MLX_KEY_UP)
	{
		if (wallcheck("UP", main) == false)
		{
			main->player->position.y += main->player->delta.y;
			main->player->position.x += main->player->delta.x;
		}
	}
	if (keydata.key == MLX_KEY_DOWN)
	{
		if (wallcheck("DOWN", main) == false)
		{
			main->player->position.y -= main->player->delta.y;
			main->player->position.x -= main->player->delta.x;
		}
	}
	if (keydata.key == MLX_KEY_LEFT)
	{
		main->player->angle -= 0.1;
		if (main->player->angle < 0)
			main->player->angle += 2 * M_PI;
		main->player->delta.x = cos(main->player->angle) * ANGLEOFFSET;
		main->player->delta.y = sin(main->player->angle) * ANGLEOFFSET;
	}
	if (keydata.key == MLX_KEY_RIGHT)
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
