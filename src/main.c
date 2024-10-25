/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:36:14 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/25 13:24:54 by mstrauss         ###   ########.fr       */
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

	atexit(leaks);
	main = init_structs();
	parse_arguments(ac, av, main);
	init_data(main);
	mlx_loop_hook(main->mlx, fps, main);
	mlx_loop_hook(main->mlx, key_hooks, main);
	mlx_loop_hook(main->mlx, loop_hooks, main);
	mlx_set_cursor_mode(main->mlx, MLX_MOUSE_HIDDEN);
	// mlx_set_cursor(main->mlx, MLX_CURSOR_CROSSHAIR);
	mlx_loop(main->mlx);
	end_game(main);
	free_structs(main);
	return (0);
}
