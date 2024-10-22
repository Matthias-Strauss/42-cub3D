/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:07 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/22 13:14:07 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(t_main *main)
{
	set_types(main);
	load_textures(main);
	convert_colors(main);
	check_for_garbage(main);
	get_map_coor(main);
	check_map_coor(main);
	get_player_pos(main->map_data);
	get_map_dimensions(main->map_data);
	create_2d_map_squared(main);
}

void	create_2d_map_squared(t_main *main)
{
	int		i;
	int		tmp_len;
	char	**map;
	char	**old_map;

	i = -1;
	old_map = main->map_data->map_coor;
	map = ft_calloc(main->map_data->map_height + 1, sizeof(char *));
	while (++i < main->map_data->map_height)
	{
		map[i] = ft_calloc(main->map_data->map_width + 1, sizeof(char));
		tmp_len = ft_strlen(old_map[i]);
		ft_memcpy(map[i], old_map[i], tmp_len);
		while (tmp_len < main->map_data->map_width)
		{
			map[i][tmp_len] = '1';
			tmp_len++;
		}
	}
	free_matrix(old_map);
	main->map_data->map_coor = map;
}

// int	get_longest_line(t_main *main)
// {
// 	int		max_line_len;
// 	int		len_buffer;
// 	char	*line_buffer;

// 	max_line_len = 0;
// 	line_buffer = get_next_line(main->parser->map_fd, false);
// 	while (line_buffer)
// 	{
// 		len_buffer = ft_strlen(line_buffer);
// 		if (len_buffer > max_line_len)
// 			max_line_len = len_buffer;
// 		line_buffer = get_next_line(main->parser->map_fd, false);
// 	}
// 	return (max_line_len);
// }
