/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:41:41 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/23 21:43:12 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_movement(t_main *main)
{
	mouse_mode_t	mode;

	mlx_set_mouse_pos(main->mlx, main->mlx->width / 2, main->mlx->height / 2);
}
