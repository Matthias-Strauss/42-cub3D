/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:07 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/31 15:16:55 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	character_check(char *to_check, t_main *main)
{
	int		i;

	i = 0;
	while (to_check[i] && to_check[i] != '\n')
	{
		i = skip_whitespaces(to_check, i);
		if (to_check[i] != '1' && to_check[i] != '0')
		{
			if (main->parser->player_position_found == true)
				error_exit(main, ERR_WCF_C);
			else if (to_check[i] == 'N')
				main->parser->player_position_found = true;
			else if (to_check[i] == 'E')
				main->parser->player_position_found = true;
			else if (to_check[i] == 'S')
				main->parser->player_position_found = true;
			else if (to_check[i] == 'W')
				main->parser->player_position_found = true;
			else
				error_exit(main, ERR_WCF_C);
		}
		i++;
	}
}

void	check_map_layout(t_main *main)
{
	int	i;

	i = 0;
	while (main->map_data->map_layout[i])
	{
		character_check(main->map_data->map_layout[i], main);
		i++;
	}
}

void	parse_map(t_main *main)
{
	set_types(main);
	get_map_layout(main);
	check_map_layout(main);
}
