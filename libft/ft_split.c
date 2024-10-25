/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:32:13 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/24 18:48:58 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int_fast32_t	ft_countdelim(char const *s, char c)
{
	char			*ptr;
	int_fast32_t	count;
	int_fast32_t	i;
	int_fast32_t	chkvl;

	ptr = (char *)s;
	count = 0;
	i = 0;
	chkvl = 1;
	while (ptr[i])
	{
		if (ptr[i] == c && chkvl == 0)
			chkvl = 1;
		if (ptr[i] != c && chkvl == 1)
		{
			count++;
			chkvl = 0;
		}
		i++;
	}
	return (count);
}

/// @brief Frees a float pointer array and its content
/// @param arr The array to be freed
/// @param amount The amount of entries to be freed
/// @return
static void	ft_clean(char **arr, int_fast32_t amount)
{
	while (amount >= 0)
		free(arr[amount--]);
	free(arr);
}

char	**ft_split_malloc_helper(int_fast32_t wrdcnt)
{
	char	**arr;

	arr = malloc(sizeof(char *) * (wrdcnt + 1));
	if (arr == NULL)
		return (NULL);
	arr[wrdcnt] = NULL;
	return (arr);
}

/// @brief		Allocates (with malloc(3)) and returns an array
///				of strings obtained by splitting ’s’ using the
///				character ’c’ as a delimiter. The array must end
///				with a NULL pointer.
/// @param s 	String to be split.
/// @param c 	Delimiter character.
/// @return 	array of new strings resulting from the split.
///				NULL if the allocation fails.
char	**ft_split(char const *s, char c)
{
	char			**arr;
	int_fast32_t	i;
	int_fast32_t	j;
	int_fast32_t	wrdcnt;

	i = 0;
	j = 0;
	wrdcnt = ft_countdelim(s, c);
	arr = ft_split_malloc_helper(wrdcnt);
	if (arr == NULL)
		return (NULL);
	while (j < wrdcnt)
	{
		while (s[i] == c)
			i++;
		if (wrdcnt == 1 && ft_strchr(&s[i], c) == NULL)
			arr[j] = ft_substr(&s[i], 0, ft_strlen(s));
		else
			arr[j] = ft_substr(&s[i], 0, ft_strchr(&s[i], c) - &s[i]);
		if (arr[j] == NULL)
			return (ft_clean(arr, j), NULL);
		i = i + ft_strlen(arr[j]);
		j++;
	}
	return (arr);
}
