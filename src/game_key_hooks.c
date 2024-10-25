/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:36:42 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/25 16:06:25 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	esc_key(mlx_key_data_t keydata, t_main *main)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(main->mlx);
}

void	minimap(mlx_key_data_t keydata, t_main *main)
{
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		main->minimap->enabled = !main->minimap->enabled;
}

void	key_hooks(mlx_key_data_t keydata, void *main)
{
	esc_key(keydata, (t_main *)main);
	minimap(keydata, (t_main *)main);
}
