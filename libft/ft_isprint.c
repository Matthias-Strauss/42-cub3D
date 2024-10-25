/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:39:18 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/24 18:44:30 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief checks if a character is in the printable ascii range
/// @param c character to be checked
/// @return 1 if printable, 0 if non-printable
int_fast32_t	ft_isprint(int_fast32_t c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
