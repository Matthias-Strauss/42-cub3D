/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:59:18 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/27 20:52:48 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	parse_arguments(int num_arg_strings, char **arg_strings, t_main *main)
{
	parse_num_arg_strings(num_arg_strings, main);
	parse_map_file_format(arg_strings[1], main);
	parse_copy_map(main);
	parse_map(main);
}
