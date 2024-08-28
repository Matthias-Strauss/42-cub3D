/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:18:59 by kklockow          #+#    #+#             */
/*   Updated: 2023/03/30 19:51:37 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*arr;
	char	*rra;

	arr = (char *)src;
	rra = (char *)dest;
	if (dest == 0 && src == 0)
		return (0);
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n--)
			rra[n] = arr[n];
	}
	return (dest);
}
