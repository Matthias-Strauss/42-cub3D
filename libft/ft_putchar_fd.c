/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:48:44 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/24 18:40:59 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Outputs the character ’c’ to the given file descriptor.
/// @param c 	Character to output.
/// @param fd 	File descriptor on which to write.

void	ft_putchar_fd(char c, int_fast32_t fd)
{
	write(fd, &c, 1);
}
