/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:36:14 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/27 17:33:45 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_main_struct(t_main *main)
{
	if (main->parser != NULL)
		free (main->parser);
	if (main != NULL)
		free (main);
}

void	error_exit(t_main *main)
{
	free_main_struct(main);
	perror("Error\ncub3d");
	exit (errno);
}

void	init_parser_struct(t_main *main)
{
	t_parser	*parser;

	parser = malloc(sizeof (t_parser) * 1);
	if (parser == NULL)
	{
		errno = ENOMEM;
		error_exit (main);
	}
	main->parser = parser;
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

void	check_num_arg_strings(int num_arg_strings, t_main *main)
{
	if (num_arg_strings != 2)
	{
		errno = EINVAL;
		error_exit (main);
	}
}

void	parse_arguments(int num_arg_strings, char **arg_strings, t_main *main)
{
	check_num_arg_strings(num_arg_strings, main);
	// check_map_file_format(arg_strings[1], game);
	// open_map();
	// parse_map();
	main->parser->map_path_stack = arg_strings[1];
}

int	main(int ac, char **av)
{
	t_main	*main;

	main = init_main_struct();
	parse_arguments(ac, av, main);
	free_main_struct(main);
	return (0);
}
