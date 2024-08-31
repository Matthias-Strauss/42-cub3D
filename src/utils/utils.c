/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:20:11 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/31 13:46:41 by kklockow         ###   ########.fr       */
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
	while (str[i] == ' ')
		i--;
	return (i);
}
