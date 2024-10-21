/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_dda_algo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:16:39 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/21 14:13:42 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	step_x(t_ray *ray)
{
	ray->side_dist.x += ray->delta_dist.x;
	ray->map_box.x += ray->step.x;
	if (ray->step.x == 1)
		ray->side = EAST;
	else
		ray->side = WEST;
}

void	step_y(t_ray *ray)
{
	ray->side_dist.y += ray->delta_dist.y;
	ray->map_box.y += ray->step.y;
	if (ray->step.y == 1)
		ray->side = NORTH;
	else
		ray->side = SOUTH;
}

void	dda_algo(t_main *main, t_ray *ray)
{
	bool	hit;

	hit = false;
	while (hit == false)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			step_x(ray);
		}
		else
		{
			step_y(ray);
		}
		if (main->map_data->map_coor[ray->map_box.y][ray->map_box.x] == '1')
			hit = true;
	}
}
