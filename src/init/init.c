/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:59:22 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/27 19:28:53 by kklockow         ###   ########.fr       */
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

void	init_nested_structs(t_main *main)
{
	init_parser_struct(main);
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
	init_nested_structs(main);
	return (main);
}
