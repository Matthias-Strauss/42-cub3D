/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_map_layout.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:35:46 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/31 11:39:06 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	first_line_check_on(char *current)
{
	int	i;

	i = 0;
	while (current[i] && current[i] != '\n')
	{
		i = skip_whitespaces(current, i);
		if (current[i] != '1')
			return (false);
		i++;
	}
	if (i == 0)
		return (false);
	return (true);
}

int	find_first_line(t_main *main)
{
	int		i;
	char	*current;

	i = 0;
	while (main->parser->map_copy_heap[i])
	{
		current = main->parser->map_copy_heap[i];
		if (first_line_check_on(current) == true)
			return (i);
		i++;
	}
	return (0);
}

char	*add_to_map_string(char *map_string, char *to_add)
{
	char	*map_string_old;

	map_string_old = map_string;
	map_string = ft_strjoin(map_string_old, "\1");
	save_free(map_string_old);
	map_string_old = map_string;
	map_string = ft_strjoin(map_string_old, to_add);
	save_free(map_string_old);
	return (map_string);
}

void	get_map_layout(t_main *main)
{
	int		i;
	char	*map_string;

	i = find_first_line(main);
	if (i == 0)
		error_exit(main, 8);
	map_string = calloc(1, 1);
	while (main->parser->map_copy_heap[i])
	{
		map_string = add_to_map_string(map_string, main->parser->map_copy_heap[i]);
		i++;
	}
	main->map_data->map_layout = ft_split(map_string, '\1');
	free(map_string);
}
