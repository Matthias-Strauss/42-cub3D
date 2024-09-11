/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:50:10 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/11 16:52:35 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	distance(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	draw_wall_segment(t_ray ray, double angle, t_main *main, int start, int color)
{
	int		line_height;
	int		i;
	float	line_offset;
	float	fisheye_fix;

	fisheye_fix = main->player->angle - angle;
	if (fisheye_fix < 0)
		fisheye_fix += 2 * M_PI;
	if (fisheye_fix > 2 * M_PI)
		fisheye_fix -= 2 * M_PI;
	ray.distance = ray.distance * cos(fisheye_fix);
	line_height = (TILESIZE * HEIGHT) / ray.distance;
	if (line_height > HEIGHT)
		line_height = HEIGHT;
	line_offset = (HEIGHT / 2) - (line_height / 2);
	i = 0;
	while (i < LT)
	{
		draw_line(start + i, line_offset, start + i, line_offset + line_height, main, color);
		i++;
	}
}

void	draw_current_wall_segment(t_main *main, double angle, int start)
{
	t_ray	ray_h;
	t_ray	ray_v;

	ray_h = ray_horizontal(main, angle);
	ray_v = ray_vertical(main, angle);
	if (ray_h.no_hit == true && ray_v.no_hit == true)
		return ;
	else if (ray_h.distance < ray_v.distance)
	{
		draw_wall_segment(ray_h, angle, main, start, main->map_data->ceiling_color);
		draw_line(main->player->position.x, main->player->position.y, ray_h.x, ray_h.y, main, 65280);
	}
	else
	{
		draw_wall_segment(ray_v, angle, main, start,  main->map_data->ceiling_color + 50);
		draw_line(main->player->position.x, main->player->position.y, ray_v.x, ray_v.y, main, 65280);
	}
}

void	draw_rays(t_main *main)
{
	float	angle;
	int		i;
	int		start;

	angle = main->player->angle - DR * (FOV / 2);
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	start = 550;
	i = 0;
	while (i < FOV)
	{
		draw_current_wall_segment(main, angle, start);
		start += LT;
		i++;
		angle += DR;
		if (angle < 0)
			angle += 2 * M_PI;
		if (angle > 2 * M_PI)
			angle -= 2 * M_PI;
	}
}
