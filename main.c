/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:36:14 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/31 15:29:24 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	t_main	*main;

	main = init_structs();
	parse_arguments(ac, av, main);
	// int	i = 0;
	// while (main->map_data->map_layout[i])
	// {
	// 	printf("%s", main->map_data->map_layout[i]);
	// 	i++;
	// }
	printf("%s\n", main->map_data->north_texture);
	printf("%s\n", main->map_data->east_texture);
	printf("%s\n", main->map_data->west_texture);
	printf("%s\n", main->map_data->south_texture);
	printf("%s\n", main->map_data->ceiling_color);
	printf("%s\n", main->map_data->floor_color);
	free_structs(main);
	return (0);
}
