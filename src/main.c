/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:36:14 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/23 19:01:05 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	leaks(void)
{
	system("leaks cub3D");
}

int	main(int ac, char **av)
{
	t_main	*main;

	atexit(leaks);
	main = init_structs();
	parse_arguments(ac, av, main);
	init_data(main);
	mlx_loop_hook(main->mlx, fps, main);
	mlx_loop_hook(main->mlx, key_hooks, main);
	mlx_loop_hook(main->mlx, loop_hooks, main);
	mlx_loop(main->mlx);
	end_game(main);
	free_structs(main);
	return (0);
}
