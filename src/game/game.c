/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:46:37 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/04 16:04:45 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	start_game(t_main *main)
{
	main->mlx = mlx_init(1024, 1024, "cub3D", false);
	if (main->mlx == NULL)
		error_exit(main, mlx_errno);
	mlx_key_hook(main->mlx, &key_hooks, main);
	mlx_loop(main->mlx);
}

void	end_game(t_main *main)
{
	mlx_terminate(main->mlx);
}
