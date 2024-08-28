/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_low_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:17:42 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/23 12:27:10 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_low_x(unsigned int n, int write_val)
{
	char	c;

	if (n >= 16)
	{
		write_val = ft_printf_low_x(n / 16, write_val);
		if (write_val == -1)
			return (write_val);
		write_val = ft_printf_low_x(n % 16, write_val);
		if (write_val == -1)
			return (write_val);
	}
	if (n <= 9)
	{
		c = n + 48;
		write_val = write_val + write (1, &c, 1);
	}
	if (n > 9 && n < 16)
	{
		c = n + 87;
		write_val = write_val + write (1, &c, 1);
	}
	return (write_val);
}
