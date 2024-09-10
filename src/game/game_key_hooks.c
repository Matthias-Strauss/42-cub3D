/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:36:42 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/10 16:34:46 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	escape(mlx_key_data_t keydata, t_main *main)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(main->mlx);
}

void	movement(mlx_key_data_t keydata, t_main *main)
{
	if (keydata.key == MLX_KEY_W)
	{
		main->player->position.y += main->player->delta.y;
		main->player->position.x += main->player->delta.x;
	}
	if (keydata.key == MLX_KEY_S)
	{
		main->player->position.y -= main->player->delta.y;
		main->player->position.x -= main->player->delta.x;
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
