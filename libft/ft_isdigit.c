/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:39:45 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/24 18:44:16 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief checks if a character is a digit
/// @param num character to check
/// @return returns character if it IS a digit
/// 		returns 0 if character is NOT a digit
int_fast32_t	ft_isdigit(int_fast32_t num)
{
	if (num >= '0' && num <= '9')
		return (num);
	return (0);
}
