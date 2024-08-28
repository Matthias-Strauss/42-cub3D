/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:53:10 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/23 12:25:30 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_pointer_address(size_t n, int write_val)
{
	char	c;

	if (n >= 16)
	{
		write_val = get_pointer_address(n / 16, write_val);
		if (write_val == -1)
			return (write_val);
		write_val = get_pointer_address(n % 16, write_val);
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

int	ft_printf_p(size_t n)
{
	int		write_val;

	write_val = write (1, "0x", 2);
	if (write_val == -1)
		return (write_val);
	write_val = write_val + get_pointer_address(n, 0);
	return (write_val);
}
