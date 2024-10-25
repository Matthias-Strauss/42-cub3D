/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:36:14 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/25 16:12:52 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	leaks(void)
{
	system("leaks cub3D");
}

int_fast32_t	main(int_fast32_t ac, char **av)
{
	t_main	*main;

	// atexit(leaks);
	main = init_structs();
	parse_arguments(ac, av, main);
	init_data(main);
	mlx_loop_hook(main->mlx, fps, main);
	mlx_loop_hook(main->mlx, loop_hooks, main);
	mlx_key_hook(main->mlx, key_hooks, main);
	mlx_set_cursor_mode(main->mlx, MLX_MOUSE_HIDDEN);
	// mlx_set_cursor(main->mlx, MLX_CURSOR_CROSSHAIR);
	mlx_set_mouse_pos(main->mlx, main->mlx->width / 2, main->mlx->height / 2);
	mlx_loop(main->mlx);
	end_game(main);
	free_structs(main);
	return (0);
}

// void my_keyhook(mlx_key_data_t keydata, void* param)
// {
// 	// If we PRESS the 'J' key, print "Hello".
// 	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
// 		puts("Hello ");

// 	// If we RELEASE the 'K' key, print "World".
// 	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
// 		puts("World");

// 	// If we HOLD the 'L' key, print "!".
// 	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
// 		puts("!");
// }

// int32_t	main(void)
// {
// 	mlx_t* mlx;

// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 		return (EXIT_FAILURE);

// 	mlx_key_hook(mlx, &my_keyhook, NULL);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }