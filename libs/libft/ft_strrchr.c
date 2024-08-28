/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:13:18 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/01 19:45:18 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i > 0)
	{
		i--;
		if (s[i] == (char)c)
			return ((char *) s + i);
	}
	if (s[ft_strlen((char *)s)] == (char)c)
		return ((char *) s + ft_strlen((char *)s));
	return (0);
}
