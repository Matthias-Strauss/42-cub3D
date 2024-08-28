/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:36:14 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/28 15:19:46 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_matrix(char **to_free)
{
	int	i;

	i = 0;
	if (to_free != NULL)
	{
		while (to_free[i] != NULL)
		{
			free (to_free[i]);
			i++;
		}
		free (to_free);
	}
}

void	free_structs(t_main *main)
{
	if (main->parser != NULL)
	{
		free_matrix (main->parser->map_copy_heap);
		free (main->parser);
	}
	if (main != NULL)
		free (main);
}

void	error_exit(t_main *main)
{
	free_structs(main);
	perror("Error\ncub3d");
	exit (errno);
}

int	main(int ac, char **av)
{
	t_main	*main;
	int		i;

	i = 0;
	main = init_structs();
	parse_arguments(ac, av, main);
	while (main->parser->map_copy_heap[i] != NULL)
	{
		printf("%s", main->parser->map_copy_heap[i]);
		i++;
	}
	free_structs(main);
	return (0);
}
