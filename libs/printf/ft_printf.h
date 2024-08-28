/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:15:42 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/20 14:34:18 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_printf_c(char c);
int	ft_printf(const char *s, ...);
int	ft_printf_putchar(int i, const char *format_string);
int	ft_printf_s(char *s);
int	ft_printf_percent(void);
int	ft_printf_i_d(int n);
int	ft_printf_u(unsigned int n);
int	ft_printf_low_x(unsigned int i, int null);
int	ft_printf_up_x(unsigned int n, int write_val);
int	ft_printf_p(size_t n);

#endif
