/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 04:26:42 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/20 04:27:18 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	safe_free(void *to_free)
{
	if (to_free != NULL)
		free(to_free);
}

void	free_matrix(char **to_free)
{
	int	i;

	i = 0;
	if (to_free != NULL)
	{
		while (to_free[i] != NULL)
		{
			safe_free(to_free[i]);
			i++;
		}
		safe_free(to_free);
	}
}
