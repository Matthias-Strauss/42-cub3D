/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_for_garbage.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:57:49 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/04 17:42:08 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_type(char *current)
{
	int	i;

	i = skip_whitespaces(current, 0);
	if (ft_strncmp(current + i, "NO", 2) == 0)
		return (true);
	if (ft_strncmp(current + i, "EA", 2) == 0)
		return (true);
	if (ft_strncmp(current + i, "SO", 2) == 0)
		return (true);
	if (ft_strncmp(current + i, "WE", 2) == 0)
		return (true);
	if (ft_strncmp(current + i, "C", 1) == 0)
		return (true);
	if (ft_strncmp(current + i, "F", 1) == 0)
		return (true);
	return (false);
}

bool	is_empty(char *current)
{
	int	i;

	i = skip_whitespaces(current, 0);
	if (ft_strncmp(current + i, "\n", 1) == 0)
		return (true);
	return (false);
}

void	check_for_garbage(t_main *main)
{
	int		i;
	char	*current;

	i = 0;
	while (i < main->parser->last_type_index)
	{
		current = main->parser->map_copy_heap[i];
		if (is_type(current) == false && is_empty(current) == false)
			error_exit(main, ERR_GFM);
		i++;
	}
}
