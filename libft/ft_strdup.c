/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:08:24 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/27 14:52:48 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Allocates sufficient memory for a copy of the string s1,
/// 			does the copy, and returns a pointer to it.
/// @param s1 	String 1.
/// @return 	Pointer to allocated memory.
///				if fail; return NULL and set errno to ENOMEM.
char	*ft_strdup(const char *s1)
{
	int_fast32_t		len;
	int_fast32_t		i;
	char				*ptr;

	len = ft_strlen(s1) + 1;
	i = -1;
	ptr = malloc(len);
	if (ptr == NULL)
		return (NULL);
	while (++i <= len && s1[i])
		ptr[i] = s1[i];
	ptr[i] = '\0';
	return (ptr);
}
