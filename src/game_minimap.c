/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:50:49 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/25 21:00:27 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	retc(int_fast32_t r, int_fast32_t g, int_fast32_t b, int_fast32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_tile_minimap(t_main *main, int_fast32_t y, int_fast32_t x, char id)
{
	int_fast32_t	i;
	int_fast32_t	ii;
	int_fast32_t	color;

	if (id == '1')
		color = retc(75, 75, 75, 255);
	else
		color = retc(139, 69, 19, 255);
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
	int_fast32_t		x_i;
	int_fast32_t		y_i;
	t_point				player;

	player.x = (main->player->pos.x) * main->mlx->width
		/ MINIMAP_SIZE / main->map_data->map_width;
	player.y = (main->player->pos.y) * main->mlx->height
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
	char				**map;
	int_fast32_t		y;
	int_fast32_t		x;

	map = main->map_data->map_coor;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1' || map[y][x] == ' ')
				draw_tile_minimap(main, y, x, '1');
			else
				draw_tile_minimap(main, y, x, '0');
			x++;
		}
		y++;
	}
	draw_player_minimap(main);
}
