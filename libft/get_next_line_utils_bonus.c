/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:18:01 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/04 19:45:26 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gl(const char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr_gl(const char *s, char c)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (s[i] == c)
		return (1);
	return (0);
}

void	ft_bzero_gl(void *s, size_t n)
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

void	*ft_calloc_gl(size_t count, size_t size)
{
	void	*tmp;

	tmp = malloc(sizeof(char) * (count * size));
	if (!tmp)
		return (NULL);
	ft_bzero_gl(tmp, count * size);
	return (tmp);
}

char	*ft_strjoin_gl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = ft_calloc_gl(1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	dst = ft_calloc_gl((ft_strlen_gl(s1) + ft_strlen_gl(s2) + 1), sizeof(char));
	if (dst == NULL)
		return (free(s1), NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		dst[i++] = s2[j++];
	free(s1);
	return (dst);
}
