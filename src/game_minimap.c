/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:50:49 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/20 03:01:51 by kklockow         ###   ########.fr       */
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
		color = return_color(0, 0, 0, 0);
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
	int		i;
	int		ii;
	t_point	player;
	t_point	direc;

	player.x = (main->player->position.x) / TILESIZE
		* main->mlx->width / MINIMAP_SIZE / main->map_data->map_width;
	player.y = (main->player->position.y) / TILESIZE
		* main->mlx->height / MINIMAP_SIZE / main->map_data->map_height;
	ii = -4;
	while (ii < 5)
	{
		i = -4;
		while (i < 5)
		{
			mlx_put_pixel(main->minimap, player.x + i, player.y + ii, 255);
			i++;
		}
		ii++;
	}
	direc.x = player.x + (main->player->delta.x / TILESIZE
			* main->mlx->width / MINIMAP_SIZE / main->map_data->map_width) * 5;
	direc.y = player.y + (main->player->delta.y / TILESIZE * main->mlx->height
			/ MINIMAP_SIZE / main->map_data->map_height) * 5;
	draw_line_minimap(player, direc, main, return_color(255, 0, 0, 255));
}

void	draw_minimap(t_main *main)
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
				draw_tile_minimap(main, x, y, '1');
			else if (map[y][x] != ' ')
				draw_tile_minimap(main, x, y, '0');
			x++;
		}
		y++;
	}
	draw_player_minimap(main);
}
