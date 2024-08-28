/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:28:50 by kklockow          #+#    #+#             */
/*   Updated: 2023/03/23 11:06:33 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1c;
	unsigned char	*s2c;

	i = 0;
	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	while (n > 0 && (s1c[i] != '\0' || s2c[i] != '\0'))
	{
		if ((s1c[i] - s2c[i]) == 0)
			n--;
		else
			return ((s1c[i] - s2c[i]));
		i++;
	}
	return (0);
}
