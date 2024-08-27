/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_copy_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:03 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/27 20:12:28 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	parse_open_map(t_main *main)
{
	main->parser->map_fd = open(main->parser->map_path_stack, O_RDONLY);
	if (main->parser->map_fd < 0)
		error_exit (main);
}

void	parse_close_map(t_main *main)
{
	main->parser->map_fd = close(main->parser->map_fd);
	if (main->parser->map_fd < 0)
		error_exit (main);
}

void	parse_create_copy(t_main *main)
{
	main->parser->map_copy_heap = malloc(sizeof (char **) * 1);
	if (main->parser->map_copy_heap == NULL)
	{
		errno = ENOMEM;
		error_exit(main);
	}
}

void	parse_copy_map(t_main *main)
{
	parse_open_map(main);
	parse_create_copy(main);
	parse_close_map(main);
}
