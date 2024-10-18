/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:38:24 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/18 21:13:27 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_tile_minimap(t_main *main, int x, int y, char id)
{
	int	i;
	int	ii;
	int	color;

	if (id == '1')
		color = 16777215;
	else
		color = 0;
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

// void	draw_map(t_main *main)
// {
// 	char	**map;
// 	int		y;
// 	int		x;

// 	map = main->map_data->map_layout;
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

void	draw_player_minimap(t_main *main)
{
	t_point	start_point;
	t_point	end_point;

	start_point.x = (main->player->position.x - TILESIZE / 2) / TILESIZE
		* main->mlx->width / MINIMAP_SIZE / main->map_data->map_width;
	start_point.y = (main->player->position.y - TILESIZE / 2) / TILESIZE
		* main->mlx->height / MINIMAP_SIZE / main->map_data->map_height;
	end_point.x = start_point.x + (main->player->delta.x / TILESIZE
			* main->mlx->width / MINIMAP_SIZE / main->map_data->map_width) * 5;
	end_point.y = start_point.y + (main->player->delta.y / TILESIZE
			* main->mlx->height / MINIMAP_SIZE / main->map_data->map_height)
		* 5;
	draw_line_minimap(start_point, end_point, main,
		main->map_data->ceiling_color);
}

void	draw_tile(t_main *main, int x, int y, char id)
{
	int	i;
	int	ii;
	int	color;

	if (id == '1')
		color = main->map_data->ceiling_color;
	else
		return ;
	// color = main->map_data->floor_color;
	x = x * TILESIZE;
	y = y * TILESIZE;
	ii = 1;
	while (ii < TILESIZE - 1)
	{
		i = 0;
		while (i < TILESIZE - 1)
		{
			if (x + i < main->mlx->width && y + ii < main->mlx->height)
				mlx_put_pixel(main->image, x + i, y + ii, color);
			i++;
		}
		ii++;
	}
}

// void	draw_map(t_main *main)
// {
// 	char	**map;
// 	int		y;
// 	int		x;

// 	map = main->map_data->map_layout;
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

void	draw_player(t_main *main)
{
	t_point	start_point;
	t_point	end_point;

	start_point.x = main->player->position.x;
	start_point.y = main->player->position.y;
	end_point.x = start_point.x + (main->player->delta.x / 2);
	end_point.y = start_point.y + (main->player->delta.y / 2);
	draw_line(start_point, end_point, main, 65535);
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

void	draw_background(t_main *main)
{
	uint32_t	x;
	unsigned int	y;

	y = 0;
	while(y < main->image->height / 2)
	{
		x = 0;
		while(x < main->image->width)
		{
			mlx_put_pixel(main->image, x, y, main->map_data->ceiling_color);
			x++;
		}
		y++;
	}
	while(y < main->image->height)
	{
		x = 0;
		while(x < main->image->width)
		{
			mlx_put_pixel(main->image, x, y, main->map_data->floor_color);
			x++;
		}
		y++;
	}
}

void	loop_hooks(void *param)
{
	t_main *main;

	main = param;
	// mlx_delete_image(main->mlx, main->minimap);
	// mlx_delete_image(main->mlx, main->image);
	// main->image = mlx_new_image(main->mlx, WIDTH, HEIGHT);
	// main->minimap = mlx_new_image(main->mlx, WIDTH / MINIMAP_SIZE, HEIGHT / MINIMAP_SIZE);
	// draw_map(main);
	draw_background(main);
	draw_rays(main);
	draw_minimap(main);
	// draw_background(main);
	// draw_player(main);
	// mlx_image_to_window(main->mlx, main->minimap, 0, 0);
	// mlx_image_to_window(main->mlx, main->image, 0, 0);
	// mlx_image_to_window(main->mlx, main->minimap, 0, 0);
}
