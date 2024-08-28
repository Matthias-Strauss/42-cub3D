/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:31:16 by kklockow          #+#    #+#             */
/*   Updated: 2023/03/23 20:55:30 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	int		new;

	sign = 1;
	i = 0;
	new = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		new = new * 10 + str[i] - '0';
		i++;
	}
	return (new * sign);
}
