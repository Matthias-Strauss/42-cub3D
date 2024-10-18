/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_horizontal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:22:06 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/18 17:08:00 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_ray	h_set_values_for_current_angle(t_ray ray, t_main *main)
{
	if (ray.angle > M_PI)
	{
		ray.y = (((int)main->player->position.y >> 6) << 6) - 0.0002;
		ray.x = (main->player->position.y - ray.y) * ray.tan + main->player->position.x;
		ray.y_offset = -64;
		ray.x_offset = -ray.y_offset * ray.tan;
	}
	else if (ray.angle < M_PI)
	{
		ray.y = (((int)main->player->position.y >> 6) << 6) + 64;
		ray.x = (main->player->position.y - ray.y) * ray.tan + main->player->position.x;
		ray.y_offset = 64;
		ray.x_offset = -ray.y_offset * ray.tan;
	}
	else //if (ray.angle == 0 || ray.angle == M_PI)
	{
		ray.x = main->player->position.x;
		ray.y = main->player->position.y;
		ray.dof = RD;
		ray.no_hit = true;
	}
	return (ray);
}

t_ray	h_cast_current_ray(t_ray ray, t_main *main)
{
	int		mx;
	int		my;

	while (ray.dof < RD)
	{
		mx = (int)ray.x >> 6;
		my = (int)ray.y >> 6;
		if (mx >= 0 && mx <= main->map_data->map_width && my >= 0 && my < main->map_data->map_height && mx < ft_strlen(main->map_data->map_layout[my]) && main->map_data->map_layout[my][mx] == '1')
		{
			ray.distance = distance(main->player->position.x, main->player->position.y, ray.x, ray.y);
			ray.dof = RD;
		}
		else
		{
			ray.x += ray.x_offset;
			ray.y += ray.y_offset;
			ray.dof++;
			if (ray.dof == RD)
				ray.no_hit = true;
		}
	}
	return (ray);
}

t_ray	ray_horizontal(t_main *main, t_ray ray)
{
	ray.dof = 0;
	ray.no_hit = false;
	ray.tan = -1 / tan(ray.angle);
	ray.distance = 100000;
	ray = h_set_values_for_current_angle(ray, main);
	ray = h_cast_current_ray(ray, main);
	return (ray);
}
