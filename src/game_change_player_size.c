/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_change_player_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:02:18 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/25 13:50:17 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_player_height(t_main *main)
{
	if (mlx_is_key_down(main->mlx, MLX_KEY_KP_SUBTRACT))
	{
		// main->player
		main->player->height += 0.5;
	}
	if (mlx_is_key_down(main->mlx, MLX_KEY_KP_ADD))
	{
		main->player->height -= 0.5;
	}
}
