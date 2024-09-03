/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:20:11 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/03 18:35:28 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	skip_whitespaces(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int	reverse_skip_whitespaces(char *str, int i)
{
	if (str[i] == '\n' && i > 0)
		i--;
	while (str[i] == ' ' && i > 0)
		i--;
	return (i);
}
