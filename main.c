/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:36:14 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/03 12:01:48 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	t_main	*main;
	mlx_t	*mlx;
	mlx_image_t	*image;

	main = init_structs();
	parse_arguments(ac, av, main);


	mlx = mlx_init(256, 256, "cub3d", false);
	image = mlx_new_image(mlx, 256, 256);

	for (int i = 0; i < 256; i++)
		mlx_put_pixel(image, i, i, main->map_data->ceiling_color);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);


	free_structs(main);
	return (0);
}
