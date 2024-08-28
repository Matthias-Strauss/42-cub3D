/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:39:44 by kklockow          #+#    #+#             */
/*   Updated: 2023/03/30 17:03:47 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*arr;

	i = 0;
	arr = (unsigned char *)str;
	while (i < n)
	{
		arr[i] = c;
		i++;
	}
	return (arr);
}
