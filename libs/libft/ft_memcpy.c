/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:35:32 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/04 21:00:08 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*arr;
	char	*rra;

	i = 0;
	arr = (char *)src;
	rra = (char *)dst;
	if (dst == 0 && src == 0)
		return (0);
	while (n > i)
	{
		rra[i] = arr[i];
		i++;
	}
	return ((void *)dst);
}
