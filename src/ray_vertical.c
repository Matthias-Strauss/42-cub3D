/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vertical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:22:56 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/19 15:05:56 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	v_set_values_for_current_angle(t_ray ray, t_main *main)
{
	if (ray.angle > (M_PI / 2) && ray.angle < (M_PI * 3 / 2))
	{
		ray.x = (((int)main->player->position.x >> 6) << 6) - 0.0002;
		ray.y = (main->player->position.x - ray.x) * ray.tan
			+ main->player->position.y;
		ray.x_offset = -64;
		ray.y_offset = -ray.x_offset * ray.tan;
	}
	else if (ray.angle < (M_PI / 2) || ray.angle > (M_PI * 3 / 2))
	{
		ray.x = (((int)main->player->position.x >> 6) << 6) + 64;
		ray.y = (main->player->position.x - ray.x) * ray.tan
			+ main->player->position.y;
		ray.x_offset = 64;
		ray.y_offset = -ray.x_offset * ray.tan;
	}
	else // if (ray.angle == 0 || ray.angle == M_PI)
	{
		ray.x = main->player->position.x;
		ray.y = main->player->position.y;
		ray.dof = RD;
		ray.no_hit = true;
	}
	return (ray);
}

t_ray	v_cast_current_ray(t_ray ray, t_main *main)
{
	int	mx;
	int	my;

	while (ray.dof < RD)
	{
		mx = (int)ray.x >> 6;
		my = (int)ray.y >> 6;
		if (mx >= 0 && mx <= main->map_data->map_width && my >= 0
			&& my < main->map_data->map_height
			&& mx < ft_strlen(main->map_data->map_layout[my])
			&& main->map_data->map_layout[my][mx] == '1')
		{
			ray.distance = distance(main->player->position.x,
					main->player->position.y, ray.x, ray.y);
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

t_ray	ray_vertical(t_main *main, t_ray ray)
{
	ray.dof = 0;
	ray.no_hit = false;
	ray.tan = -tan(ray.angle);
	ray.distance = 100000;
	ray = v_set_values_for_current_angle(ray, main);
	ray = v_cast_current_ray(ray, main);
	return (ray);
}
