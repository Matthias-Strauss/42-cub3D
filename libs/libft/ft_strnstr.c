/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:24:58 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/04 21:00:41 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	o;

	i = 0;
	o = 0;
	if (needle[o] == '\0')
		return ((char *) haystack);
	if (haystack == needle)
		return ((char *)needle);
	while ((haystack[i] != '\0') && (i < len))
	{
		while (haystack[i + o] == needle[o] && (o + i < len))
		{
			o++;
			if (needle[o] == '\0')
				return ((char *) haystack + i);
		}
		i++;
		o = 0;
	}
	return (0);
}
