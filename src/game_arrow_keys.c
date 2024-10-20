/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_arrow_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:53:49 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/20 00:54:13 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
