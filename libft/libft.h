/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:43:04 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/24 18:43:36 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LIBFT.H
#ifndef LIBFT_H
# define LIBFT_H
// EXTERNAL
# include <errno.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

ssize_t				write(int_fast32_t fd, const void *buf, size_t count);

// ############################# STRING HANDLING ##############################
int_fast32_t		ft_atoi(const char *str);
float				ft_atof(const char *str);
char				*ft_itoa(int_fast32_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int_fast32_t		ft_isalnum(int_fast32_t c);
int_fast32_t		ft_isalpha(int_fast32_t num);
int_fast32_t		ft_isascii(int_fast32_t c);
int_fast32_t		ft_isdigit(int_fast32_t num);
int_fast32_t		ft_isprint(int_fast32_t c);
void				*ft_memchr(const void *s, int_fast32_t c, size_t n);
int_fast32_t		ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int_fast32_t c, size_t len);
char				*ft_strchr(const char *s, int_fast32_t c);
char				*ft_strrchr(const char *s, int_fast32_t c);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int_fast32_t		ft_strlen(const char *s);
int_fast32_t		ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int_fast32_t		ft_tolower(int_fast32_t c);
int_fast32_t		ft_toupper(int_fast32_t c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_putchar_fd(char c, int_fast32_t fd);
void				ft_putstr_fd(char *s, int_fast32_t fd);
void				ft_putendl_fd(char *s, int_fast32_t fd);
void				ft_putnbr_fd(int_fast32_t n, int_fast32_t fd);
void				ft_striteri(char *s, void (*f)(unsigned int_fast32_t,
							char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int_fast32_t,
							char));
char				**ft_split(char const *s, char c);

// ##############################  LINKED LISTS  ##############################
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int_fast32_t		ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// #############################  GET NEXT LINE  #############################
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char				*get_next_line(int_fast32_t fd, bool finished);
char				*ft_strjoin_gl(char *s1, char *s2);
int_fast32_t		ft_strchr_gl(const char *s, char c);
size_t				ft_strlen_gl(const char *c);
void				ft_bzero_gl(void *s, size_t n);
void				*ft_calloc_gl(size_t count, size_t size);

#endif