/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:21:49 by kklockow          #+#    #+#             */
/*   Updated: 2023/05/12 16:12:41 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_text(int fd, char *text)
{
	int		count_byte;
	char	*buffer;

	count_byte = 1;
	buffer = ft_calloc_gl((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	while (count_byte != 0 && ft_strchr_gl(text, '\n') == 0)
	{
		count_byte = read(fd, buffer, BUFFER_SIZE);
		if (count_byte == -1)
		{
			free(buffer);
			free(text);
			text = NULL;
			return (NULL);
		}
		buffer[count_byte] = '\0';
		text = ft_strjoin_gl(text, buffer);
	}
	free(buffer);
	return (text);
}

char	*get_the_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_calloc_gl((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*update_text(char *text)
{
	char	*updated;
	int		i;
	int		j;

	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (text[i] == '\0')
	{
		free(text);
		return (NULL);
	}
	updated = ft_calloc_gl((ft_strlen_gl(text) - i + 1), sizeof(char));
	if (!updated)
		return (free(text), NULL);
	if (text[i] == '\n')
		i++;
	j = 0;
	while (text[i] != '\0')
		updated[j++] = text[i++];
	free(text);
	return (updated);
}

char	*get_next_line(int fd)
{
	static char		*text[4096];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text[fd] = read_text(fd, text[fd]);
	if (text[fd] == NULL)
		return (free(text[fd]), NULL);
	line = get_the_line(text[fd]);
	text[fd] = update_text(text[fd]);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	fd1;
// 	// int	fd2;
// 	int	i;

// 	i = 0;
// 	fd1 = open("test.txt", O_RDONLY);
// 	// fd2 = open("test2.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	// printf("%s", get_next_line(0));
// 	// printf("%s", get_next_line(0));
// 	close(fd1);
// 	// close(fd2);
// 	return (0);
// }