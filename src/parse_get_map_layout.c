/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_map_coor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:35:46 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/19 15:07:56 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	first_line_check_on(char *current)
{
	int_fast32_t	i;

	i = skip_whitespaces(current, 0);
	if (current[i] != '\n' && current[i] != '\0')
		return (true);
	return (false);
}

int_fast32_t	find_first_line(t_main *main)
{
	int_fast32_t		i;
	char				*current;

	i = main->parser->last_type_index + 1;
	while (main->parser->map_copy_heap[i])
	{
		current = main->parser->map_copy_heap[i];
		if (first_line_check_on(current) == true)
			return (i);
		i++;
	}
	return (0);
}

char	*add_to_map_str(char *map_string, char *to_add)
{
	char	*map_string_old;

	if (to_add[skip_whitespaces(to_add, 0)] == '\n')
	{
		free(map_string);
		return (NULL);
	}
	map_string_old = map_string;
	map_string = ft_strjoin(map_string_old, to_add);
	safe_free(map_string_old);
	return (map_string);
}

void	get_map_coor(t_main *main)
{
	int_fast32_t		i;
	char				*map_string;

	i = find_first_line(main);
	if (i == 0)
		error_exit(main, 8);
	map_string = ft_calloc(1, 1);
	while (main->parser->map_copy_heap[i])
	{
		map_string = add_to_map_str(map_string, main->parser->map_copy_heap[i]);
		if (map_string == NULL)
			error_exit(main, ERR_ELM);
		i++;
	}
	main->map_data->map_coor = ft_split(map_string, '\n');
	free(map_string);
}
