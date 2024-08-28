/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:07 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/28 18:59:51 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	set_type_paths(t_main *main)
{
	int		i;
	char	*current;
	char	*copy;

	i = 0;
	while (main->parser->map_copy_heap[i])
	{
		current = main->parser->map_copy_heap[i];
		if (!ft_strncmp(current, "NO", 2))
		{
			copy = malloc(sizeof (char) * (ft_strlen(current)));
			ft_strlcpy(copy, current, ft_strlen(current));
			main->map_data->north_texture = copy;
			free (copy);
		}
		i++;
	}
}

void	parse_map(t_main *main)
{
	set_type_paths(main);
	ft_printf("%s\n", main->map_data->north_texture);
	// get_map_content()
}
