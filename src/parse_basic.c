/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:41:46 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/24 18:40:59 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_num_arg_strings(int_fast32_t num_arg_strings, t_main *main)
{
	if (num_arg_strings != 2)
		error_exit(main, ERR_WAA);
}

void	parse_map_file_format(char *arg_map_path, t_main *main)
{
	int_fast32_t	map_path_len;

	map_path_len = ft_strlen(arg_map_path);
	if (map_path_len < 4)
		error_exit(main, ERR_WFF);
	if (ft_strncmp((arg_map_path + map_path_len - 4), ".cub", 4) != 0)
		error_exit(main, ERR_WFF);
	main->parser->map_path_stack = arg_map_path;
}
