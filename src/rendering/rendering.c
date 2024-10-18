/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:21:34 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/16 17:46:33 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_3d(t_main *main)
{
	int		i;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	i = 0;
	while (i < main->mlx->width)
	{
		camera_x = 2 * i / (double)main->mlx->width - 1;
	}
}

/* ------------------------------ INIT TEXTURES ----------------------------- */
// mlx_texture_t

// mlx_texture_t* mlx_load_png(const char* path);

void	load_textures(t_main *main)
{
	main->textures[0] = mlx_load_png("./textures/wall_north.png");
	main->textures[1] = mlx_load_png("./textures/wall_south.png");
	main->textures[2] = mlx_load_png("./textures/wall_east.png");
	main->textures[3] = mlx_load_png("./textures/floor.png");
	main->textures[4] = mlx_load_png("./textures/ceiling.png");
}
