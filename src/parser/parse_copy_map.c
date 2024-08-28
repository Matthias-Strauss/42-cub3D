/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_copy_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:03 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/28 16:40:04 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	parse_open_map(t_main *main)
{
	main->parser->map_fd = open(main->parser->map_path_stack, O_RDONLY);
	if (main->parser->map_fd < 0)
		error_exit (main);
}


char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = 0;
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dst[i] = s2[j];
		j++;
		i++;
	}
	free(s1);
	free(s2);
	dst[i] = '\0';
	return (dst);
}

void	parse_create_copy(t_main *main)
{
	char	*line_buffer;
	char	*line_buffer_delimited;
	char	*file_string;

	file_string = calloc(1, 1);
	line_buffer = get_next_line(main->parser->map_fd);
	while (line_buffer)
	{
		line_buffer_delimited = ft_strjoin(line_buffer, "\1");
		free (line_buffer);
		file_string = ft_strjoin_free(file_string, line_buffer_delimited);
		line_buffer = get_next_line(main->parser->map_fd);
	}
	free(line_buffer);
	main->parser->map_copy_heap = ft_split(file_string, '\1');
	free(file_string);
}

void	parse_close_map(t_main *main)
{
	main->parser->map_fd = close(main->parser->map_fd);
	if (main->parser->map_fd < 0)
		error_exit (main);
}

void	parse_copy_map(t_main *main)
{
	parse_open_map(main);
	parse_create_copy(main);
	parse_close_map(main);
}
