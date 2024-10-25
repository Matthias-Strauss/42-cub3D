/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_crouch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:04:50 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/24 20:06:04 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	crouch(t_main *main)
{
	if (mlx_is_key_down(main->mlx, MLX_KEY_C))
	{
		main->player->pos.z -= 0.1;
	}
	else
	{
		main->player->pos.z += 0.1;
	}
}
