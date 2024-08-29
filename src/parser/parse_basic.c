/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:41:46 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/29 19:40:17 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_num_arg_strings(int num_arg_strings, t_main *main)
{
	if (num_arg_strings != 2)
		error_exit (main, ERR_WAA_C);
}

void	parse_map_file_format(char *arg_map_path, t_main *main)
{
	int	map_path_len;

	map_path_len = ft_strlen(arg_map_path);
	if (ft_strncmp((arg_map_path + map_path_len - 4), ".cub", 4) != 0)
		error_exit(main, ERR_WFF_C);
	main->parser->map_path_stack = arg_map_path;
}
