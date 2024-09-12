/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:50:10 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/12 18:15:43 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	distance(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	draw_wall_segment(t_ray ray, t_main *main, int start, int color)
{
	int		i;
	t_point	start_point;
	t_point	end_point;

	ray.fisheye_fix = main->player->angle - ray.angle;
	if (ray.fisheye_fix < 0)
		ray.fisheye_fix += 2 * M_PI;
	if (ray.fisheye_fix > 2 * M_PI)
		ray.fisheye_fix -= 2 * M_PI;
	ray.distance = ray.distance * cos(ray.fisheye_fix);
	ray.line_height = (TILESIZE * HEIGHT) / ray.distance;
	if (ray.line_height >= HEIGHT - LT)
		ray.line_height = HEIGHT - LT;
	ray.line_offset = (HEIGHT / 2) - (ray.line_height / 2);
	i = 0;
	while (i < LT)
	{
		start_point.x = start + i;
		start_point.y = ray.line_offset;
		end_point.x = start + i;
		end_point.y = ray.line_offset + ray.line_height;
		draw_line(start_point, end_point, main, color);
		i++;
	}
}

void	draw_current_wall_segment(t_main *main, t_ray ray, int start)
{
	t_ray	ray_h;
	t_ray	ray_v;

	ray_h = ray_horizontal(main, ray);
	ray_v = ray_vertical(main, ray);
	if (ray_h.no_hit == true && ray_v.no_hit == true)
		return ;
	else if (ray_h.distance < ray_v.distance)
	{
		draw_wall_segment(ray_h, main, start, main->map_data->ceiling_color);
	}
	else
	{
		draw_wall_segment(ray_v, main, start, main->map_data->ceiling_color + 50);
	}
}

void	draw_rays(t_main *main)
{
	t_ray	ray;
	int		i;
	int		start;

	ray.angle = main->player->angle - ANGLE_INCREMENT * (FOV / 2);
	if (ray.angle < 0)
		ray.angle += 2 * M_PI;
	if (ray.angle > 2 * M_PI)
		ray.angle -= 2 * M_PI;
	start = LT;
	i = 0;
	while (i < FOV)
	{
		draw_current_wall_segment(main, ray, start);
		start += LT;
		i++;
		ray.angle += ANGLE_INCREMENT;
		if (ray.angle < 0)
			ray.angle += 2 * M_PI;
		if (ray.angle > 2 * M_PI)
			ray.angle -= 2 * M_PI;
	}
}
