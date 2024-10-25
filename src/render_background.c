/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:54:38 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/25 16:14:21 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_background(t_main *main)
{
	uint_fast32_t	x;
	uint_fast32_t	y;
	mlx_image_t		*background;

	y = 0;
	background = mlx_new_image(main->mlx, main->mlx->width, main->mlx->height
			* 2);
	while (y < background->height / 2)
	{
		x = 0;
		while (x < background->width)
			mlx_put_pixel(background, x, y, main->map_data->ceiling_color);
		x++;
		y++;
	}
	while (y < background->height)
	{
		x = 0;
		while (x < background->width)
			mlx_put_pixel(background, x, y, main->map_data->floor_color);
		x++;
		y++;
	}
}

void	draw_background_colored(t_main *main)
{
	ft_memcpy(main->image->pixels, main->background->pixels
		+ ((main->image->height + main->player->pitch) / 2 * main->image->width
			* sizeof(uint32_t)), main->image->width * main->image->height
		* sizeof(uint32_t));
}
