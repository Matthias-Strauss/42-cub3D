/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:15:46 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/25 12:05:54 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(int i, const char *format_string, va_list args)
{
	int		numchr;

	numchr = 0;
	if (format_string[i] == 'c')
		numchr = ft_printf_c(va_arg(args, int));
	if (format_string[i] == 's')
		numchr = ft_printf_s(va_arg(args, char *));
	if (format_string[i] == 'p')
		numchr = ft_printf_p(va_arg(args, size_t));
	if (format_string[i] == 'd')
		numchr = ft_printf_i_d(va_arg(args, int));
	if (format_string[i] == 'i')
		numchr = ft_printf_i_d(va_arg(args, int));
	if (format_string[i] == 'u')
		numchr = ft_printf_u(va_arg(args, unsigned int));
	if (format_string[i] == 'x')
		numchr = ft_printf_low_x(va_arg(args, unsigned int), 0);
	if (format_string[i] == 'X')
		numchr = ft_printf_up_x(va_arg(args, unsigned int), 0);
	if (format_string[i] == '%')
		numchr = ft_printf_percent();
	return (numchr);
}

int	ft_printf(const char *format_string, ...)
{
	va_list	args;
	int		i;
	int		numchr;

	i = 0;
	numchr = 0;
	va_start(args, format_string);
	while (format_string[i] != '\0')
	{
		if (format_string[i] == '%' && format_string[i + 1])
		{
			i++;
			numchr = numchr + format(i, format_string, args);
		}
		else
		{
			numchr = numchr + ft_printf_putchar(i, format_string);
		}
		i++;
		if (numchr < 0)
			return (-1);
	}
	va_end(args);
	return (numchr);
}

// int	main(void)
// {
// 	char	c;
// 	char	*s;
// 	char	*formatstr;

// 	formatstr = " ";
// 	s = "kartoffelgulasch";
// 	c = '0';
// 	ft_printf("%p\n", "");
// 	printf("%p", "");
// 	return (0);
// }
