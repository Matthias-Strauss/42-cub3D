/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:20:01 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/01 14:55:24 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libs/libs.h"
#include "error_codes.h"

//////////////////////////////////////////////////////////////////////////////

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

//////////////////////////////////////////////////////////////////////////////

typedef struct s_parser
{
	char	*map_path_stack;
	char	**map_copy_heap;
	int		map_fd;
	int		last_type_index;
}	t_parser;

//////////////////////////////////////////////////////////////////////////////

typedef struct s_map_data
{
	char	*north_texture;
	char	*east_texture;
	char	*south_texture;
	char	*west_texture;
	char	*floor_color;
	char	*ceiling_color;
	char	**map_layout;
	int		map_width;
	int		map_height;
	char	player_orientation;
	t_point	player_position;
}	t_map_data;

//////////////////////////////////////////////////////////////////////////////

typedef struct s_main
{
	t_parser	*parser;
	t_map_data	*map_data;
}	t_main;

//////////////////////////////////////////////////////////////////////////////

// init.c

t_main	*init_structs(void);

//////////////////////////////////////////////////////////////////////////////

// parser.c

void	parse_arguments(int num_arg_strings, char **arg_strings, t_main *main);

// parse_basic.c

void	parse_num_arg_strings(int num_arg_strings, t_main *main);
void	parse_map_file_format(char *arg_map_path, t_main *main);

// parse_copy_map.c

void	parse_copy_map(t_main *main);

// parse_map.c

void	parse_map(t_main *main);

// parse_set_types.c

void	set_types(t_main *main);

// parse_get_map_layout.c

void	get_map_layout(t_main *main);

// parse_check_map_layout.c

void	check_map_layout(t_main *main);

// parse_get_missing_information.c

int		get_player_position(t_map_data *map_data);
void	get_map_dimensions(t_map_data *map_data);

// parse_utils.c

char	*ft_strjoin_free(char *s1, char *s2);
char	*copy_path(char *to_copy, t_main *main);

//////////////////////////////////////////////////////////////////////////////

// free.c

void	free_matrix(char **to_free);
void	free_structs(t_main *main);
void	free_parser_struct(t_main *main);
void	save_free(void *to_free);

//////////////////////////////////////////////////////////////////////////////

// error.c

void	error_exit(t_main *main, int error_code);

//////////////////////////////////////////////////////////////////////////////

// utils.c

int		skip_whitespaces(char *str, int i);
int		reverse_skip_whitespaces(char *str, int i);