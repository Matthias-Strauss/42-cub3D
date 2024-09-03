/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:07 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/03 12:03:12 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	next_comma(char *str, int start)
{
	while (str[start] && str[start] != ',')
		start++;
	return (start);
}

int	last_comma(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0 && str[i] != ',')
		i--;
	return (i);
}

bool	check_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int	get_only_number(char *str, int start)
{
	char	*buffer;
	int		number;

	buffer = ft_substr(str, start, next_comma(str, start) - start);
	if (check_chars(buffer) == false)
	{
		free(buffer);
		return (-1);
	}
	printf("[%s]\n", buffer);
	number = ft_atoi(buffer);
	if (number > 255 || number < 0)
	{
		free(buffer);
		return (-1);
	}
	free(buffer);
	return (number);
}

int	convert_string_to_color(t_main *main, char *str)
{
	int		r;
	int		g;
	int		b;

	r = get_only_number(str, 0);
	if (r == -1)
		error_exit(main, ERR_CNC_C);
	g = get_only_number(str, next_comma(str, 0) + 1);
	if (g == -1)
		error_exit(main, ERR_CNC_C);
	b = get_only_number(str, last_comma(str) + 1);
	if (b == -1)
		error_exit(main, ERR_CNC_C);
	return (r << 24 | g << 16 | b << 8 | 100);
}

void	convert_colors(t_main *main)
{
	main->map_data->ceiling_color = convert_string_to_color(main, main->parser->ceiling_color);
	main->map_data->floor_color = convert_string_to_color(main, main->parser->floor_color);
}

void	parse_map(t_main *main)
{
	set_types(main);
	check_for_garbage(main);
	get_map_layout(main);
	check_map_layout(main);
	get_player_position(main->map_data);
	get_map_dimensions(main->map_data);
	convert_colors(main);
}
