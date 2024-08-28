/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:59:22 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/27 20:44:16 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_parser_struct(t_main *main)
{
	main->parser = malloc(sizeof (t_parser) * 1);
	if (main->parser == NULL)
	{
		errno = ENOMEM;
		error_exit (main);
	}
	main->parser->map_copy_heap = NULL;
	main->parser->map_fd = 0;
	main->parser->map_path_stack = NULL;
}

t_main	*init_main_struct(void)
{
	t_main	*main;

	main = malloc(sizeof (t_main) * 1);
	if (main == NULL)
	{
		errno = ENOMEM;
		error_exit (main);
	}
	main->parser = NULL;
	return (main);
}

t_main	*init_structs(void)
{
	t_main	*main;

	main = init_main_struct();
	init_parser_struct(main);
	return (main);
}
