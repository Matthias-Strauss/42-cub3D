/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:09:34 by kklockow          #+#    #+#             */
/*   Updated: 2023/03/23 15:20:06 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	o;
	size_t	j;

	o = 0;
	i = 0;
	j = ft_strlen(dst) + ft_strlen((char *)src);
	if (size == 0 || size <= ft_strlen(dst))
		return (ft_strlen((char *)src) + size);
	i = ft_strlen(dst);
	while (src[o] != '\0' && i < size - 1)
	{
		dst[i] = src[o];
		o++;
		i++;
	}
	dst[i] = '\0';
	return (j);
}
