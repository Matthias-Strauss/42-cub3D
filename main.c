/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:36:14 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/28 16:56:51 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(t_main *main)
{
	free_structs(main);
	perror("Error\ncub3d");
	exit (errno);
}

int	main(int ac, char **av)
{
	t_main	*main;

	main = init_structs();
	parse_arguments(ac, av, main);
	free_structs(main);
	return (0);
}
