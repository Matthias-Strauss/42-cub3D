/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:48:08 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/04 17:37:42 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = 0;
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dst[i] = s2[j];
		j++;
		i++;
	}
	save_free(s1);
	save_free(s2);
	dst[i] = '\0';
	return (dst);
}

int	get_path_len(char *to_copy, t_main *main)
{
	int	start;
	int	end;
	int	len;

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
	char	*in_copy;
	int		start;
	int		len;

	start = skip_whitespaces(to_copy, 0);
	len = get_path_len(to_copy, main);
	in_copy = ft_substr(to_copy, start, len);
	if (in_copy == NULL)
		error_exit(main, ERR_UAM);
	return (in_copy);
}

int	skip_whitespaces(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int	reverse_skip_whitespaces(char *str, int i)
{
	if (str[i] == '\n' && i > 0)
		i--;
	while (str[i] == ' ' && i > 0)
		i--;
	return (i);
}
