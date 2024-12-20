/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:36:42 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/27 22:32:32 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	esc_key(mlx_key_data_t keydata, t_main *main)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(main->mlx);
}

void	shift_key(mlx_key_data_t keydata, t_main *main)
{
	if (keydata.key == MLX_KEY_LEFT_SHIFT)
	{
		if (keydata.action == MLX_PRESS)
			main->player->speed = PLAYER_SPEED * 2.5;
		else
			main->player->speed = PLAYER_SPEED;
	}
}

void	key_hooks(mlx_key_data_t keydata, void *main)
{
	esc_key(keydata, (t_main *)main);
	toggle_minimap(keydata, (t_main *)main);
	toggle_sky(keydata, (t_main *)main);
	toggle_wall_texture(keydata, (t_main *)main);
	toggle_mouse(keydata, (t_main *)main);
	toggle_fullscreen(keydata, (t_main *)main);
	shift_key(keydata, (t_main *)main);
}
