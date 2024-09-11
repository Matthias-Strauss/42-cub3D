/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:20:01 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/11 18:11:50 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "error_codes.h"

# define WIDTH 			2400
# define HEIGHT 		1200
# define TILESIZE 		64
# define ANGLEOFFSET 	5
# define DR 			0.0174533	//radian increment value
# define RD 			32			//render distance
# define FOV 			90			//field of view
# define LT 			10			//line thickness

//////////////////////////////////////////////////////////////////////////////

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

//////////////////////////////////////////////////////////////////////////////

typedef struct s_parser
{
	char	*map_path_stack;
	char	**map_copy_heap;
	int		map_fd;
	int		last_type_index;
	char	*floor_color;
	char	*ceiling_color;
}	t_parser;

//////////////////////////////////////////////////////////////////////////////

typedef struct s_map_data
{
	char	*north_texture;
	char	*east_texture;
	char	*south_texture;
	char	*west_texture;
	int		floor_color;
	int		ceiling_color;
	char	**map_layout;
	int		map_width;
	int		map_height;
	char	player_orientation;
	t_point	player_position;
}	t_map_data;

//////////////////////////////////////////////////////////////////////////////

typedef struct s_player
{
	t_point	position;
	t_point	delta;
	double	angle;
}	t_player;

//////////////////////////////////////////////////////////////////////////////

typedef struct s_ray
{
	float	x;
	float	y;
	float	x_offset;
	float	y_offset;
	float	tan;
	double	angle;
	float	distance;
	bool	no_hit;
	int		dof;
}	t_ray;

//////////////////////////////////////////////////////////////////////////////

typedef struct s_main
{
	t_parser	*parser;
	t_map_data	*map_data;
	t_player	*player;
	mlx_t		*mlx;
	mlx_image_t	*image;
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

void	get_player_position(t_map_data *map_data);
void	get_map_dimensions(t_map_data *map_data);

// parse_check_for_garbage.c

void	check_for_garbage(t_main *main);

// parse_convert_colors.c

void	convert_colors(t_main *main);

// parse_utils.c

char	*ft_strjoin_free(char *s1, char *s2);
char	*copy_path(char *to_copy, t_main *main);
int		skip_whitespaces(char *str, int i);
int		reverse_skip_whitespaces(char *str, int i);

//////////////////////////////////////////////////////////////////////////////

// game.c

void	start_game(t_main *main);
void	during_game(t_main *main);
void	end_game(t_main *main);

// game_key_hooks.c

void	key_hooks(mlx_key_data_t keydata, void *main);

// game_loop_hooks.c

void	loop_hooks(void *param);
void	draw_line(int x1, int y1, int x2, int y2, t_main *main, int color);

//////////////////////////////////////////////////////////////////////////////

// ray.c

void	draw_rays(t_main *main);
float	distance(float ax, float ay, float bx, float by);

// ray_horizontal.c

t_ray	ray_horizontal(t_main *main, double angle);

// ray_vertical.c

t_ray	ray_vertical(t_main *main, double angle);

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

#endif
