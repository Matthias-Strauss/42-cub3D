/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:20:01 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/28 13:44:15 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include "libs/libs.h"

typedef struct s_parser
{
	char	*map_path_stack;
	char	**map_copy_heap;
	int		map_fd;
}	t_parser;

typedef struct s_main
{
	t_parser	*parser;
}	t_main;

//init.c

t_main	*init_structs(void);

//parser.c

void	parse_arguments(int num_arg_strings, char **arg_strings, t_main *main);

// parse_basic.c

void	parse_num_arg_strings(int num_arg_strings, t_main *main);
void	parse_map_file_format(char *arg_map_path, t_main *main);

// parse_copy_map.c

void	parse_copy_map(t_main *main);

// parse_map.c

void	parse_map(t_main *main);

//main.c

void	error_exit(t_main *main);