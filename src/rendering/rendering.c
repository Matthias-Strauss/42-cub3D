/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:21:34 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/12 18:58:15 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_3d(t_main *main)
{
	int		i;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	i = 0;
	while (i < main->mlx->width)
	{
		camera_x = 2 * i / (double)main->mlx->width - 1;
		
	}
	
}
