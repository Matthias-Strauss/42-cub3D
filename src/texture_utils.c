/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:28:23 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/23 18:15:04 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* ------------------------------ INIT TEXTURES ----------------------------- */
// mlx_texture_t

// mlx_texture_t* mlx_load_png(const char* path);

void	load_textures(t_main *main)
{
	main->textures[0] = NULL;
	main->textures[1] = NULL;
	main->textures[2] = NULL;
	main->textures[3] = NULL;
	main->textures[0] = mlx_load_png(main->map_data->north_texture);
	if (main->textures[0] == NULL)
		error_exit(main, mlx_errno);
	main->textures[1] = mlx_load_png(main->map_data->east_texture);
	if (main->textures[1] == NULL)
		error_exit(main, mlx_errno);
	main->textures[2] = mlx_load_png(main->map_data->south_texture);
	if (main->textures[2] == NULL)
		error_exit(main, mlx_errno);
	main->textures[3] = mlx_load_png(main->map_data->west_texture);
	if (main->textures[3] == NULL)
		error_exit(main, mlx_errno);
	main->textures[4] = NULL;
}
