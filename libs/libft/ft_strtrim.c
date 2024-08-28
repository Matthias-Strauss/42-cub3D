/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:33:33 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/04 21:00:46 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static size_t	front(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	l;

	l = 0;
	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		while (set[i] != '\0')
		{
			if (s1[j] == set[i])
				l++;
			i++;
		}
		i = 0;
		if (l > 0)
			j++;
		else
			return (j);
		l = 0;
	}
	return (j);
}

static size_t	back(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	l;

	l = 0;
	i = 0;
	if (!s1 || s1[0] == '\0')
		return (0);
	j = ft_strlen(s1) - 1;
	while (j >= 0)
	{
		while (set[i] != '\0')
		{
			if (s1[j] == set[i])
				l++;
			i++;
		}
		i = 0;
		if (l > 0)
			j--;
		else
			return (j);
		l = 0;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	o;

	j = 0;
	if (!s1 && s1[0] == '\0')
		return (NULL);
	i = front(s1, set);
	o = back(s1, set) + 1;
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	return (ft_substr(s1, i, o - i));
}
