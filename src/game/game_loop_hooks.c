/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:38:24 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/12 20:16:52 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_tile(t_main *main, int x, int y, char id)
{
	int	i;
	int	ii;
	int	color;

	if (id == '1')
		color = 0;
	else
		color = 16777215;
	x = x * WIDTH / MINIMAP_SIZE / main->map_data->map_width;
	y = y * HEIGHT / MINIMAP_SIZE / main->map_data->map_height;
	ii = 0;
	while (ii <= HEIGHT / MINIMAP_SIZE / main->map_data->map_height)
	{
		i = 0;
		while (i <= WIDTH / MINIMAP_SIZE / main->map_data->map_width)
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

void	draw_player(t_main *main)
{
	t_point	start_point;
	t_point	end_point;

	start_point.x = (main->player->position.x - TILESIZE / 2) / TILESIZE * WIDTH / MINIMAP_SIZE / main->map_data->map_width;
	start_point.y = (main->player->position.y - TILESIZE / 2) / TILESIZE * HEIGHT / MINIMAP_SIZE / main->map_data->map_height;
	end_point.x = start_point.x + (main->player->delta.x / TILESIZE * WIDTH / MINIMAP_SIZE / main->map_data->map_width) * 10;
	end_point.y = start_point.y + (main->player->delta.y / TILESIZE * HEIGHT / MINIMAP_SIZE / main->map_data->map_height) * 10;
	draw_line(start_point, end_point, main, main->map_data->ceiling_color);
}

void	loop_hooks(void *param)
{
	t_main	*main;

	main = param;
	mlx_delete_image(main->mlx, main->image);
	main->image = mlx_new_image(main->mlx, WIDTH, HEIGHT);
	draw_rays(main);
	draw_map(main);
	draw_player(main);
	mlx_image_to_window(main->mlx, main->image, 0, 0);
}
