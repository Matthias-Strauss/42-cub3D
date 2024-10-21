/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:50:49 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/20 20:34:21 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	return_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_tile_minimap(t_main *main, int x, int y, char id)
{
	int	i;
	int	ii;
	int	color;

	if (id == '1')
		color = return_color(75, 75, 75, 255);
	else
		color = return_color(139, 69, 19, 255);
	x = x * main->mlx->width / MINIMAP_SIZE / main->map_data->map_width;
	y = y * main->mlx->height / MINIMAP_SIZE / main->map_data->map_height;
	ii = 0;
	while (ii <= main->mlx->height / MINIMAP_SIZE / main->map_data->map_height)
	{
		i = 0;
		while (i <= main->mlx->width / MINIMAP_SIZE / main->map_data->map_width)
		{
			mlx_put_pixel(main->minimap, x + i, y + ii, color);
			i++;
		}
		ii++;
	}
}

void	draw_player_minimap(t_main *main)
{
	int		x_i;
	int		y_i;
	t_point	player;

	player.x = (main->player->position.x) / TILESIZE * main->mlx->width
		/ MINIMAP_SIZE / main->map_data->map_width;
	player.y = (main->player->position.y) / TILESIZE * main->mlx->height
		/ MINIMAP_SIZE / main->map_data->map_height;
	y_i = -3;
	while (y_i < 4)
	{
		x_i = -3;
		while (x_i < 4)
		{
			mlx_put_pixel(main->minimap, player.x + x_i, player.y + y_i, 255);
			x_i++;
		}
		y_i++;
	}
}

void	draw_minimap(t_main *main)
{
	char	**map;
	int		y;
	int		x;

	map = main->map_data->map_coor;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_tile_minimap(main, x, y, '1');
			else if (map[y][x] != ' ')
				draw_tile_minimap(main, x, y, '0');
			x++;
		}
		y++;
	}
	draw_player_minimap(main);
}
