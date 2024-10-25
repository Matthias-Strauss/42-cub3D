/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:09:58 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/24 18:44:46 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Determines char string length
/// @param s String to measure
/// @return Length of string including Nul-terminator
int_fast32_t	ft_strlen(const char *s)
{
	int_fast32_t	i;

	i = -1;
	while (s[++i] != '\0')
		;
	return (i);
}
