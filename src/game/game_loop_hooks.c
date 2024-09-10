/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:38:24 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/10 19:06:58 by kklockow         ###   ########.fr       */
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
        if (x1 >= 0 && y1 >= 0 && x1 <= WIDTH && y1 <= HEIGHT)
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

	angle = main->player->angle;
	i = 0;
	while (i < 1)
	{
		dof = 0;
		aTan = -1/tan(angle);
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
			if (mx >= 0 && mx <= main->map_data->map_width && my >= 0 && my < main->map_data->map_height && main->map_data->map_layout[my][mx] == '1')
			{
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
			if (mx >= 0 && mx <= main->map_data->map_width && my >= 0 && my < main->map_data->map_height && main->map_data->map_layout[my][mx] == '1')
			{
					dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}
		draw_line(main->player->position.x, main->player->position.y, rx, ry, main);
		i++;
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
