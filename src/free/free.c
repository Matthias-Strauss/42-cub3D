/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:56:40 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/28 18:45:30 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_matrix(char **to_free)
{
	int	i;

	i = 0;
	if (to_free != NULL)
	{
		while (to_free[i] != NULL)
		{
			free (to_free[i]);
			i++;
		}
		free (to_free);
	}
}

void	free_structs(t_main *main)
{
	if (main->parser != NULL)
	{
		free_matrix (main->parser->map_copy_heap);
		free (main->parser);
	}
	if (main->map_data != NULL)
	{
		free (main->map_data->north_texture);
		free (main->map_data);
	}
	if (main != NULL)
		free (main);
}
