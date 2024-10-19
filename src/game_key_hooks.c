/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:36:42 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/20 00:44:51 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	esc_key(t_main *main)
{
	if (mlx_is_key_down(main->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(main->mlx);
}

void	left_key(t_main *main)
{
	if (mlx_is_key_down(main->mlx, MLX_KEY_LEFT))
	{
		main->player->angle -= 0.1;
		if (main->player->angle < 0)
			main->player->angle += 2 * M_PI;
		main->player->delta.x = cos(main->player->angle) * PLAYEROFFSET;
		main->player->delta.y = sin(main->player->angle) * PLAYEROFFSET;
	}
}

void	right_key(t_main *main)
{
	if (mlx_is_key_down(main->mlx, MLX_KEY_RIGHT))
	{
		main->player->angle += 0.1;
		if (main->player->angle > 2 * M_PI)
			main->player->angle -= 2 * M_PI;
		main->player->delta.x = cos(main->player->angle) * PLAYEROFFSET;
		main->player->delta.y = sin(main->player->angle) * PLAYEROFFSET;
	}
}

void	arrow_keys(t_main *main)
{
	left_key(main);
	right_key(main);
}

void	key_hooks(void *main)
{
	esc_key((t_main *)main);
	wasd_keys(((t_main *)main));
	arrow_keys((t_main *)main);
}
