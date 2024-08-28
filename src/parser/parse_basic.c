/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:41:46 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/28 14:17:35 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	parse_num_arg_strings(int num_arg_strings, t_main *main)
{
	if (num_arg_strings != 2)
	{
		errno = EINVAL;
		error_exit (main);
	}
}

void	parse_map_file_format(char *arg_map_path, t_main *main)
{
	int	map_path_len;

	map_path_len = ft_strlen(arg_map_path);
	if (ft_strncmp((arg_map_path + map_path_len - 4), ".cub", 4) != 0)
	{
		errno = 79;
		error_exit(main);
	}
	main->parser->map_path_stack = arg_map_path;
}
