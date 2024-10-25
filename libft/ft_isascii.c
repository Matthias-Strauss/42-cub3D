/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:36:24 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/24 18:44:01 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Checks if character is in standard ASCII range
/// @param c 	Character to check
/// @return 	1 if true, 0 if false
int_fast32_t	ft_isascii(int_fast32_t c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
