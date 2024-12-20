/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:00:31 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/24 18:42:17 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Checks if a character is an ASCII whitespace character
/// @param c character to check
/// @return 1 if c is a whitespace, 0 if c isn't a whitespace
static int_fast32_t	ft_isspace(int_fast32_t c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ')
		return (1);
	return (0);
}

/// @brief 		Converts a number from string to int, ignores leading whitespace
/// @param str 	String to convert.
/// @return 	Number as an int_fast32_t.
int_fast32_t	ft_atoi(const char *str)
{
	size_t			i;
	int_fast32_t	sign;
	int_fast32_t	sum;

	i = 0;
	sign = 1;
	sum = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(str[i]))
		sum = (str[i++] - '0') + (sum * 10);
	return (sign * sum);
}
