/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_copy_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:03 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/25 20:57:18 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_open_map(t_main *main)
{
	main->parser->map_fd = open(main->parser->map_path_stack, O_RDONLY);
	if (main->parser->map_fd < 0)
		error_exit(main, ERR_UOF);
}

void	parse_check_file_len(t_main *main)
{
	char				*line_buffer;
	int_fast32_t		count;

	count = 0;
	line_buffer = get_next_line(main->parser->map_fd, false);
	while (line_buffer)
	{
		safe_free(line_buffer);
		if (count > 512)
		{
			get_next_line(main->parser->map_fd, true);
			error_exit(main, ERR_MTL);
		}
		count++;
		line_buffer = get_next_line(main->parser->map_fd, false);
	}
	safe_free(line_buffer);
}

void	parse_create_copy(t_main *main)
{
	char	*line_buffer;
	char	*line_buffer_delimited;
	char	*file_string;

	file_string = ft_calloc(1, 1);
	line_buffer = get_next_line(main->parser->map_fd, false);
	while (line_buffer)
	{
		line_buffer_delimited = ft_strjoin(line_buffer, "\1");
		free(line_buffer);
		file_string = ft_strjoin_free(file_string, line_buffer_delimited);
		line_buffer = get_next_line(main->parser->map_fd, false);
	}
	safe_free(line_buffer);
	main->parser->map_copy_heap = ft_split(file_string, '\1');
	safe_free(file_string);
	if (main->parser->map_copy_heap == NULL)
		error_exit(main, ERR_UAM);
}

void	parse_close_map(t_main *main)
{
	main->parser->map_fd = close(main->parser->map_fd);
	if (main->parser->map_fd < 0)
		error_exit(main, ERR_UCF);
}

void	parse_copy_map(t_main *main)
{
	parse_open_map(main);
	parse_check_file_len(main);
	parse_close_map(main);
	parse_open_map(main);
	parse_create_copy(main);
	parse_close_map(main);
}
