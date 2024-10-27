/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus_toggles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:59:41 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/27 14:23:34 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	toggle_minimap(mlx_key_data_t keydata, t_main *main)
{
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		main->minimap->enabled = !main->minimap->enabled;
}

void	toggle_sky(mlx_key_data_t keydata, t_main *main)
{
	if (keydata.key == MLX_KEY_N && keydata.action == MLX_PRESS)
		main->texture_toggle_floor = !main->texture_toggle_floor;
}

void	toggle_wall_texture(mlx_key_data_t keydata, t_main *main)
{
	if (keydata.key == MLX_KEY_T && keydata.action == MLX_PRESS)
		main->texture_toggle_walls = !main->texture_toggle_walls;
}

void	toggle_mouse(mlx_key_data_t keydata, t_main *main)
{
	if (keydata.key == MLX_KEY_V && keydata.action == MLX_PRESS)
		main->mouse_toggle = !main->mouse_toggle;
}
