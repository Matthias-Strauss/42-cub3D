/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:20:55 by kklockow          #+#    #+#             */
/*   Updated: 2023/05/12 16:11:26 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin_gl(char *s1, char *s2);
int		ft_strchr_gl(const char *s, char c);
size_t	ft_strlen_gl(const char *c);
void	ft_bzero_gl(void *s, size_t n);
void	*ft_calloc_gl(size_t count, size_t size);

#endif
