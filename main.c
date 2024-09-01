/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:36:14 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/01 13:49:16 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	t_main	*main;

	main = init_structs();
	parse_arguments(ac, av, main);
	printf("%s\n", main->map_data->north_texture);
	printf("%s\n", main->map_data->east_texture);
	printf("%s\n", main->map_data->west_texture);
	printf("%s\n", main->map_data->south_texture);
	printf("%s\n", main->map_data->ceiling_color);
	printf("%s\n", main->map_data->floor_color);
	printf("y is %i and x is %i\n", main->map_data->player_position.y, main->map_data->player_position.x);
	printf("orientation is %c\n", main->map_data->player_orientation);
	// int	i = 0;
	// while (main->map_data->map_layout[i])
	// {
	// 	printf("%s\n", main->map_data->map_layout[i]);
	// 	i++;
	// }
	free_structs(main);
	return (0);
}
