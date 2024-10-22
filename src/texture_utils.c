/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:28:23 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/21 16:30:19 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* ------------------------------ INIT TEXTURES ----------------------------- */
// mlx_texture_t

// mlx_texture_t* mlx_load_png(const char* path);

void	load_textures(t_main *main)
{
	main->textures[0] = mlx_load_png(main->map_data->north_texture);
	main->textures[1] = mlx_load_png(main->map_data->east_texture);
	main->textures[2] = mlx_load_png(main->map_data->south_texture);
	main->textures[3] = mlx_load_png(main->map_data->west_texture);
	// main->textures[3] = mlx_load_png("./textures/floor.png");
	// main->textures[4] = mlx_load_png("./textures/ceiling.png");
	main->textures[4] = NULL;
}
