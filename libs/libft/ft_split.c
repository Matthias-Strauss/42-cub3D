/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:31:59 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/04 20:06:19 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strcount(char const *s, char c)
{
	size_t	i;
	size_t	check;

	i = 0;
	check = 0;
	while (*s)
	{
		if (*s != c && check == 0)
			i++;
			check = 1;
		if (*s == c)
			check = 0;
		s++;
	}
	return (i);
}

static size_t	getstart(char const *s, char c, size_t start)
{
	while (s[start] != '\0')
	{
		while (s[start] == c)
		{
			start++;
		}
		return (start);
	}
	return (start);
}

static size_t	getlen(char const *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
		{
			len++;
			i++;
		}
		i++;
		return (len);
	}
	return (len);
}

static void	ft_free(char **new, size_t o)
{
	while (o > 0)
	{
		free(new[o - 1]);
		o--;
	}
	free(new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	i;
	size_t	o;
	size_t	start;

	i = 0;
	o = 0;
	if (!s || c < 0 || c > 127)
		return (NULL);
	new = ft_calloc(sizeof(char *), strcount(s, c) + 1);
	if (new == NULL)
		return (NULL);
	while (o < strcount(s, c))
	{
		start = getstart(s, c, i);
		i = getstart(s, c, i);
		new[o] = ft_substr(s, start, getlen(s, c, i));
		if (new[o] == NULL)
			return (ft_free(new, o), NULL);
		i = i + getlen(s, c, i);
		o++;
	}
	new[o] = NULL;
	return (new);
}
