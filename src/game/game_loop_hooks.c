/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:38:24 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/10 20:43:24 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_tile(t_main *main, int x, int y, char id)
{
	int	i;
	int	ii;
	int	color;

	if (id == '1')
		color = main->map_data->ceiling_color;
	else
		color = main->map_data->floor_color;
	x = x * TILESIZE;
	y = y * TILESIZE;
	ii = 1;
	while (ii < TILESIZE -1)
	{
		i = 0;
		while (i < TILESIZE -1)
		{
			mlx_put_pixel(main->image, x + i, y + ii, color);
			i++;
		}
		ii++;
	}
}

void	draw_map(t_main *main)
{
	char	**map;
	int		y;
	int		x;

	map = main->map_data->map_layout;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_tile(main, x, y, '1');
			else if (map[y][x] != ' ')
				draw_tile(main, x, y, '0');
			x++;
		}
		y++;
	}
}

void	draw_line(int x1, int y1, int x2, int y2, t_main *main)
{
	int dx = abs(x2 - x1); // Calculate the difference in x
    int dy = abs(y2 - y1); // Calculate the difference in y

    int sx = (x1 < x2) ? 1 : -1; // Determine step direction for x
    int sy = (y1 < y2) ? 1 : -1; // Determine step direction for y

    int err = dx - dy; // Error term

    while (1) {
        // if (x1 >= 0 && y1 >= 0 && x1 <= WIDTH && y1 <= HEIGHT)
			mlx_put_pixel(main->image, x1, y1, main->map_data->ceiling_color); // Plot the current point
        // Check if we have reached the end point
        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        // Adjust x and error
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        // Adjust y and error
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void	draw_player(t_main *main)
{
	float	x;
	float	y;
	float	dx;
	float	dy;

	x = main->player->position.x;
	y = main->player->position.y;
	dx = main->player->delta.x;
	dy = main->player->delta.y;
	draw_line(x, y, x + dx, y + dy, main);
}

float distance(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	draw_rays(t_main *main)
{
	float	angle;
	int		i;
	int		dof;
	float	aTan;
	float	nTan;
	float	ry;
	float	rx;
	float	xo;
	float	yo;
	int		mx;
	int		my;
	float	dish;
	float	disv;
	float	dis;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	float	lineh;
	int		draw_start = 500;

	angle = main->player->angle - DR * 30;
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	i = 0;
	while (i < 60)
	{
		dof = 0;
		aTan = -1/tan(angle);
		dish = 10000;
		hx = 0;
		hy = 0;
		if (angle > M_PI)
		{
			ry = (((int)main->player->position.y >> 6) << 6) -0.0001;
			rx = (main->player->position.y - ry) * aTan + main->player->position.x;
			yo = -64;
			xo = -yo * aTan;
		}
		if (angle < M_PI)
		{
			ry = (((int)main->player->position.y >> 6) << 6) + 64;
			rx = (main->player->position.y - ry) * aTan + main->player->position.x;
			yo = 64;
			xo = -yo * aTan;
		}
		if (angle == 0 || angle == M_PI)
		{
			rx = main->player->position.x;
			ry = main->player->position.y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)rx >> 6;
			my = (int)ry >> 6;
			if (mx >= 0 && mx <= main->map_data->map_width && my >= 0 && my < main->map_data->map_height && mx < ft_strlen(main->map_data->map_layout[my]) && main->map_data->map_layout[my][mx] == '1')
			{
				dish = distance(main->player->position.x, main->player->position.y, rx, ry);
				hx = rx;
				hy = ry;
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}
		dof = 0;
		nTan = -tan(angle);
		disv = 10000;
		vx = main->player->position.x;
		vy = main->player->position.y;
		if (angle > (M_PI / 2) && angle < (M_PI * 3 / 2))
		{
			rx = (((int)main->player->position.x >> 6) << 6) -0.0001;
			ry = (main->player->position.x - rx) * nTan + main->player->position.y;
			xo = -64;
			yo = -xo * nTan;
		}
		if (angle < (M_PI / 2) || angle > (M_PI * 3 / 2))
		{
			rx = (((int)main->player->position.x >> 6) << 6) + 64;
			ry = (main->player->position.x - rx) * nTan + main->player->position.y;
			xo = 64;
			yo = -xo * nTan;
		}
		if (angle == 0 || angle == M_PI)
		{
			rx = main->player->position.x;
			ry = main->player->position.y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)rx >> 6;
			my = (int)ry >> 6;
			if (mx >= 0 && mx <= main->map_data->map_width && my >= 0 && my < main->map_data->map_height && mx < ft_strlen(main->map_data->map_layout[my]) && main->map_data->map_layout[my][mx] == '1')
			{
				disv = distance(main->player->position.x, main->player->position.y, rx, ry);
				vx = rx;
				vy = ry;
				dof = 8;
			}
			else
			{
				dof++;
				rx += xo;
				ry += yo;
			}
		}
		if (disv < dish)
		{
			rx = vx;
			ry = vy;
			dis = disv;
		}
		if (disv > dish)
		{
			rx = hx;
			ry = hy;
			dis = dish;
		}
		if (rx >= 0 && ry >= 0)
			draw_line(main->player->position.x, main->player->position.y, rx, ry, main);

		float lol = main->player->angle - angle;
		dis = dis * cos(lol);
		lineh = TILESIZE * 320 / dis;
		if (lineh > 320)
			lineh = 320;
		float lineo = 160 - lineh/2;
		for (int o = 0; o < 8; o++)
		{
			draw_line(draw_start + o, lineo, draw_start + o, lineo + lineh, main);
			draw_start++;
		}
		i++;
		angle += DR;
		if (angle < 0)
			angle += 2 * M_PI;
		if (angle > 2 * M_PI)
			angle -= 2 * M_PI;
	}
}

void	loop_hooks(void *param)
{
	t_main	*main;

	main = param;
	mlx_delete_image(main->mlx, main->image);
	main->image = mlx_new_image(main->mlx, WIDTH, HEIGHT);
	draw_map(main);
	draw_player(main);
	draw_rays(main);
	mlx_image_to_window(main->mlx, main->image, 0, 0);
}
