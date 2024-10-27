/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:33:36 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/27 16:48:47 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*copy_pixel(void *dst, const void *src, size_t n)
{
	size_t			i;
	uint32_t		*dstx;
	const uint32_t	*srcx;

	if (dst == NULL || src == NULL)
		return (dst);
	dstx = (uint32_t *)dst;
	srcx = (const uint32_t *)src;
	i = -1;
	if (dst == NULL && src == NULL)
		return (dst);
	while (++i < n)
		dstx[i] = srcx[i];
	return (dst);
}
