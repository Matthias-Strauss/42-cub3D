/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_convert_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:53:07 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/24 18:40:59 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	convert_check_characters(char *str)
{
	int_fast32_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (true);
		i++;
	}
	return (false);
}

int_fast32_t	get_only_number(char *str)
{
	int_fast32_t	number;

	if (str == NULL)
		return (-1);
	if (ft_strlen(str) > 3 || ft_strlen(str) < 1)
		return (-1);
	if (convert_check_characters(str) == true)
		return (-1);
	number = ft_atoi(str);
	if (number > 255 || number < 0)
		return (-1);
	return (number);
}

void	error_during_conversion(t_main *main, char **to_free)
{
	free_matrix(to_free);
	error_exit(main, ERR_CNC);
}

int_fast32_t	convert_string_to_color(t_main *main, char *str)
{
	int_fast32_t	r;
	int_fast32_t	g;
	int_fast32_t	b;
	char			**seperated;

	seperated = ft_split(str, ',');
	r = get_only_number(seperated[0]);
	if (r == -1)
	{
		error_during_conversion(main, seperated);
	}
	g = get_only_number(seperated[1]);
	if (g == -1)
	{
		error_during_conversion(main, seperated);
	}
	b = get_only_number(seperated[2]);
	if (b == -1)
	{
		error_during_conversion(main, seperated);
	}
	free_matrix(seperated);
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	convert_colors(t_main *main)
{
	int_fast32_t	temp;

	temp = convert_string_to_color(main, main->parser->ceiling_color);
	main->map_data->ceiling_color = temp;
	temp = convert_string_to_color(main, main->parser->floor_color);
	main->map_data->floor_color = temp;
}
