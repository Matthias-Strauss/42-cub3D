/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:50:10 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/10 23:38:59 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float distance(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

t_ray	ray_horizontal(t_main *main, double angle)
{
	t_ray	ray;
	int		dof;
	int		mx;
	int		my;

	ray.angle = angle;
	dof = 0;
	ray.tan = -1/tan(ray.angle);
	ray.distance = 10000;
	if (ray.angle > M_PI)
	{
		ray.y = (((int)main->player->position.y >> 6) << 6) -0.0001;
		ray.x = (main->player->position.y - ray.y) * ray.tan + main->player->position.x;
		ray.y_offset = -64;
		ray.x_offset = -ray.y_offset * ray.tan;
	}
	if (ray.angle < M_PI)
	{
		ray.y = (((int)main->player->position.y >> 6) << 6) + 64;
		ray.x = (main->player->position.y - ray.y) * ray.tan + main->player->position.x;
		ray.y_offset = 64;
		ray.x_offset = -ray.y_offset * ray.tan;
	}
	if (ray.angle == 0 || ray.angle == M_PI)
	{
		ray.x = main->player->position.x;
		ray.y = main->player->position.y;
		dof = RD;
	}
	while (dof < RD)
	{
		mx = (int)ray.x >> 6;
		my = (int)ray.y >> 6;
		if (mx >= 0 && mx <= main->map_data->map_width && my >= 0 && my < main->map_data->map_height && mx < ft_strlen(main->map_data->map_layout[my]) && main->map_data->map_layout[my][mx] == '1')
		{
			ray.distance = distance(main->player->position.x, main->player->position.y, ray.x, ray.y);
			dof = RD;
		}
		else
		{
			ray.x += ray.x_offset;
			ray.y += ray.y_offset;
			dof++;
		}
	}
	// draw_line(main->player->position.x, main->player->position.y, rx, ry, main, 65280);
	return (ray);
}

t_ray	ray_vertical(t_main *main, double angle)
{
	t_ray	ray;
	int		dof;
	int		mx;
	int		my;

	ray.angle = angle;
	dof = 0;
	ray.tan = -tan(ray.angle);
	ray.distance = 10000;
	if (ray.angle > (M_PI / 2) && ray.angle < (M_PI * 3 / 2))
	{
		ray.x = (((int)main->player->position.x >> 6) << 6) -0.0001;
		ray.y = (main->player->position.x - ray.x) * ray.tan + main->player->position.y;
		ray.x_offset = -64;
		ray.y_offset = -ray.x_offset * ray.tan;
	}
	if (ray.angle < (M_PI / 2) || ray.angle > (M_PI * 3 / 2))
	{
		ray.x = (((int)main->player->position.x >> 6) << 6) + 64;
		ray.y = (main->player->position.x - ray.x) * ray.tan + main->player->position.y;
		ray.x_offset = 64;
		ray.y_offset = -ray.x_offset * ray.tan;
	}
	if (ray.angle == 0 || ray.angle == M_PI)
	{
		ray.x = main->player->position.x;
		ray.y = main->player->position.y;
		dof = RD;
	}
	while (dof < RD)
	{
		mx = (int)ray.x >> 6;
		my = (int)ray.y >> 6;
		if (mx >= 0 && mx <= main->map_data->map_width && my >= 0 && my < main->map_data->map_height && mx < ft_strlen(main->map_data->map_layout[my]) && main->map_data->map_layout[my][mx] == '1')
		{
			ray.distance = distance(main->player->position.x, main->player->position.y, ray.x, ray.y);
			dof = RD;
		}
		else
		{
			ray.x += ray.x_offset;
			ray.y += ray.y_offset;
			dof++;
		}
	}
	// draw_line(main->player->position.x, main->player->position.y, rx, ry, main, 65280);
	return (ray);
}

int	draw_wall(t_ray ray, double angle, t_main *main, int start)
{
	int	line_height;

	float lol = main->player->angle - angle;
	if (lol < 0)
		lol += 2 * M_PI;
	if (lol > 2 * M_PI)
		lol -= 2 * M_PI;
	ray.distance = ray.distance * cos(lol);
	line_height = (TILESIZE * HEIGHT) / ray.distance;
	if (line_height > HEIGHT)
		line_height = HEIGHT;
	float lineo = HEIGHT/2 - line_height/2;
	for (int o = 0; o < 8; o++)
	{
		draw_line(start + o, lineo, start + o, lineo + line_height, main, main->map_data->ceiling_color);
		start++;
	}
	return (start);
}

void	draw_rays(t_main *main)
{
	t_ray	ray_h;
	t_ray	ray_v;
	float	angle;
	int		i;
	int		start = 0;

	angle = main->player->angle - DR * (FOV / 2);
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	i = 0;
	while (i < FOV)
	{

		ray_h = ray_horizontal(main, angle);
		ray_v = ray_vertical(main, angle);
		if (ray_h.distance < ray_v.distance)
			start = draw_wall(ray_h, angle, main, start);
		if (ray_h.distance > ray_v.distance)
			start = draw_wall(ray_v, angle, main, start);
		i++;
		angle += DR;
		if (angle < 0)
			angle += 2 * M_PI;
		if (angle > 2 * M_PI)
			angle -= 2 * M_PI;
	}
}
