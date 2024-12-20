/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:06:22 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/24 18:40:59 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Outputs the string ’s’ to the given file descriptor
///				followed by a newline.
/// @param s 	String to output.
/// @param fd	File descriptor on which to write.

void	ft_putendl_fd(char *s, int_fast32_t fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
