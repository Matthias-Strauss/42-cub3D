/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:36:42 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/27 14:08:16 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	esc_key(mlx_key_data_t keydata, t_main *main)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(main->mlx);
}

void	key_hooks(mlx_key_data_t keydata, void *main)
{
	esc_key(keydata, (t_main *)main);
	toggle_minimap(keydata, (t_main *)main);
	toggle_sky(keydata, (t_main *)main);
	toggle_wall_texture(keydata, (t_main *)main);
	toggle_mouse(keydata, (t_main *)main);
}
