/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:18:11 by kklockow          #+#    #+#             */
/*   Updated: 2023/03/20 18:11:19 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*arr;

	i = 0;
	arr = (char *)s;
	while (i < n)
	{
		arr[i] = '\0';
		i++;
	}
}
