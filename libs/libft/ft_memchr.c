/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:49:40 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/01 19:46:17 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*arr;

	arr = (char *)s;
	while (n > 0)
	{
		if (*arr == (char)c)
			return ((void *)arr);
		arr++;
		n--;
	}
	return (0);
}
