/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:48:08 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/29 19:40:41 by kklockow         ###   ########.fr       */
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
	free(s1);
	free(s2);
	dst[i] = '\0';
	return (dst);
}

int	get_path_len(char *to_copy, t_main *main)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (to_copy[i] == ' ')
		i++;
	while (to_copy[i] && to_copy[i] != ' ' && to_copy[i] != '\n')
	{
		i++;
		len++;
	}
	if (len == 0)
		error_exit(main, ERR_TIE_C);
	return (len);
}

char	*copy_path(char *to_copy, t_main *main)
{
	int		to;
	int		in;
	char	*in_copy;

	to = 0;
	in = 0;
	in_copy = malloc(sizeof (char) * get_path_len(to_copy, main) + 1);
	while (to_copy[to] == ' ')
		to++;
	while (to_copy[to] && to_copy[to] != ' ' && to_copy[to] != '\n')
	{
		in_copy[in] = to_copy[to];
		to++;
		in++;
	}
	in_copy[in] = '\0';
	return (in_copy);
}
