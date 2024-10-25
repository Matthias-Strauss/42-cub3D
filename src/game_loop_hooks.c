/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:38:24 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/25 15:58:02 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	init_background(t_main *main)
// {
// 	int_fast32_t	i;
// 	int_fast32_t	j;

// 	i = -1;
// 	while (++i < main->mlx->height / 2)
// 	{
// 		j = -1;
// 		while (++j < main->mlx->width)
// 			mlx_put_pixel(main->background, j, i,
// 				main->map_data->ceiling_color);
// 	}
// 	while (++i < main->mlx->height)
// 	{
// 		j = -1;
// 		while (++j < main->mlx->width)
// 			mlx_put_pixel(main->background, j, i, main->map_data->floor_color);
// 	}
// }

// void	draw_background(t_main *main)
// {
// 	ft_memcpy(main->image->pixels, main->background->pixels, main->mlx->width
// 		* main->mlx->height * sizeof(uint32_t));
// }

void	loop_hooks(void *param)
{
	t_main	*main;

	main = (t_main *)param;
	ft_bzero(main->image->pixels, main->mlx->width * main->mlx->height
		* sizeof(uint32_t));
	// draw_background(main);
	draw_floor(main);
	draw_ceiling(main);
	render_3d(main);
	draw_minimap(main);
	wasd_keys(((t_main *)main));
	arrow_keys((t_main *)main);
	mouse_movement((t_main *)main);
	change_player_height((t_main *)main);
	// crouch((t_main *)main);
}
