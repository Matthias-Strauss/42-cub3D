/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:48:08 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/24 18:40:59 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	safe_free(s1);
	safe_free(s2);
	return (joined);
}

int_fast32_t	get_path_len(char *to_copy, t_main *main)
{
	int_fast32_t	start;
	int_fast32_t	end;
	int_fast32_t	len;

	start = skip_whitespaces(to_copy, 0);
	if (to_copy[start] == '\n')
		error_exit(main, ERR_TIE);
	end = reverse_skip_whitespaces(to_copy, ft_strlen(to_copy) - 1);
	len = end - start + 1;
	if (len == 0)
		error_exit(main, ERR_TIE);
	return (len);
}

char	*copy_path(char *to_copy, t_main *main)
{
	char			*in_copy;
	int_fast32_t	start;
	int_fast32_t	len;

	start = skip_whitespaces(to_copy, 0);
	len = get_path_len(to_copy, main);
	in_copy = ft_substr(to_copy, start, len);
	if (in_copy == NULL)
		error_exit(main, ERR_UAM);
	return (in_copy);
}

int_fast32_t	skip_whitespaces(char *str, int_fast32_t i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int_fast32_t	reverse_skip_whitespaces(char *str, int_fast32_t i)
{
	if (str[i] == '\n' && i > 0)
		i--;
	while (str[i] == ' ' && i > 0)
		i--;
	return (i);
}
