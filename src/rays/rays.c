/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:50:10 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/08 18:31:22 by mstrauss         ###   ########.fr       */
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
	t_point	end;
	t_point	begin;

	end.y = HEIGHT;
	begin.y = 0;
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
		end.x = start + i;
		begin.x = start + i;
		draw_line(begin, start_point, main, main->map_data->ceiling_color);
		draw_line(start_point, end_point, main, color);
		draw_line(end_point, end, main, main->map_data->floor_color);
		i++;
	}
}

void	draw_current_wall_segment(t_main *main, t_ray ray, int start)
{
	t_ray	ray_h;
	t_ray	ray_v;

	// t_point	end;
	ray_h = ray_horizontal(main, ray);
	ray_v = ray_vertical(main, ray);
	if (ray_h.no_hit == true && ray_v.no_hit == true)
	{
		// end.x = ray_h.x;
		// end.y = ray_h.y;
		// draw_line(main->player->position, end, main,
		// main->map_data->floor_color - 1000);
		// end.x = ray_v.x;
		// end.y = ray_v.y;
		// draw_line(main->player->position, end, main,
		// main->map_data->floor_color + 1000);
		return ;
	}
	else if (ray_h.distance < ray_v.distance)
	{
		draw_wall_segment(ray_h, main, start, main->map_data->ceiling_color
			- 50);
		// end.x = ray_h.x;
		// end.y = ray_h.y;
		// draw_line(main->player->position, end, main,
		// main->map_data->floor_color - 1000);
	}
	else
	{
		draw_wall_segment(ray_v, main, start, main->map_data->ceiling_color
			+ 50);
		// end.x = ray_v.x;
		// end.y = ray_v.y;
		// draw_line(main->player->position, end, main,
		// main->map_data->floor_color + 1000);
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
	start = (WIDTH - LT * FOV) / 2;
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
