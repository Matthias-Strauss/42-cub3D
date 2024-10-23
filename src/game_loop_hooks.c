/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:38:24 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/23 19:22:36 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	draw_map(t_main *main)
// {
// 	char	**map;
// 	int		y;
// 	int		x;

// 	map = main->map_data->map_coor;
// 	y = 0;
// 	while (map[y])
// 	{
// 		x = 0;
// 		while (map[y][x])
// 		{
// 			if (map[y][x] == '1')
// 				draw_tile(main, x, y, '1');
// 			else if (map[y][x] != ' ')
// 				draw_tile(main, x, y, '0');
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_player_minimap(t_main *main)
// {
// 	t_point	start_point;
// 	t_point	end_point;

// 	start_point.x = (main->player->pos.x) / TILESIZE
// 		* main->mlx->width / MINIMAP_SIZE / main->map_data->map_width;
// 	start_point.y = (main->player->pos.y) / TILESIZE
// 		* main->mlx->height / MINIMAP_SIZE / main->map_data->map_height;
// 	end_point.x = start_point.x + (main->player->delta.x / TILESIZE
// 			* main->mlx->width / MINIMAP_SIZE / main->map_data->map_width) * 5;
// 	end_point.y = start_point.y + (main->player->delta.y / TILESIZE
// 			* main->mlx->height / MINIMAP_SIZE / main->map_data->map_height)
// 		* 5;
// 	draw_line_minimap(start_point, end_point, main,
// 		255);
// }

// void	draw_tile(t_main *main, int x, int y, char id)
// {
// 	int	i;
// 	int	ii;
// 	int	color;

// 	if (id == '1')
// 		color = main->map_data->ceiling_color;
// 	else
// 		return ;
// 	// color = main->map_data->floor_color;
// 	x = x * TILESIZE;
// 	y = y * TILESIZE;
// 	ii = 1;
// 	while (ii < TILESIZE - 1)
// 	{
// 		i = 0;
// 		while (i < TILESIZE - 1)
// 		{
// 			if (x + i < main->mlx->width && y + ii < main->mlx->height)
// 				mlx_put_pixel(main->image, x + i, y + ii, color);
// 			i++;
// 		}
// 		ii++;
// 	}
// }

// void	draw_map(t_main *main)
// {
// 	char	**map;
// 	int		y;
// 	int		x;

// 	map = main->map_data->map_coor;
// 	y = 0;
// 	while (map[y])
// 	{
// 		x = 0;
// 		while (map[y][x])
// 		{
// 			if (map[y][x] == '1')
// 				draw_tile(main, x, y, '1');
// 			else if (map[y][x] != ' ')
// 				draw_tile(main, x, y, '0');
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_player(t_main *main)
// {
// 	t_point	start_point;
// 	t_point	end_point;

// 	start_point.x = main->player->pos.x;
// 	start_point.y = main->player->pos.y;
// 	end_point.x = start_point.x + (main->player->delta.x / 2);
// 	end_point.y = start_point.y + (main->player->delta.y / 2);
// 	draw_line(start_point, end_point, main, 65535);
// }

// void	convert_pixel(uint8_t *pixel, uint32_t color)
// {
// 	*(pixel++) = (uint8_t)(color >> 24);
// 	*(pixel++) = (uint8_t)(color >> 16);
// 	*(pixel++) = (uint8_t)(color >> 8);
// 	*(pixel++) = (uint8_t)(color & 0xFF);
// }

void	init_background(t_main *main)
{
	int	i;
	int	j;

	i = -1;
	while (++i < main->mlx->height / 2)
	{
		j = -1;
		while (++j < main->mlx->width)
			mlx_put_pixel(main->background, j, i,
				main->map_data->ceiling_color);
	}
	while (++i < main->mlx->height)
	{
		j = -1;
		while (++j < main->mlx->width)
			mlx_put_pixel(main->background, j, i, main->map_data->floor_color);
	}
}

void	loop_hooks(void *param)
{
	t_main	*main;

	main = (t_main *)param;
	ft_bzero(main->image->pixels, main->mlx->width * main->mlx->height
		* sizeof(uint32_t));
	ft_memcpy(main->image->pixels, main->background->pixels, main->mlx->width
		* main->mlx->height * sizeof(uint32_t));
	render_3d(main);
	draw_minimap(main);
}
