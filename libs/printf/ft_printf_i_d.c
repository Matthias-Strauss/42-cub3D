/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:21:10 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/20 09:58:58 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_i_d(int n)
{
	char	c;
	int		write_val;

	if (n < 0 && n > -2147483648)
	{
		n = n * -1;
		write_val = write (1, "-", 1);
		if (write_val == -1)
			return (write_val);
	}
	if (n > 9)
	{
		write_val = write_i_d(n / 10);
		if (write_val == -1)
			return (write_val);
		write_val = write_i_d(n % 10);
		if (write_val == -1)
			return (write_val);
	}
	if (n < 10 && n > -2147483648)
	{
		c = n + 48;
		write_val = write (1, &c, 1);
	}
	return (write_val);
}

int	ft_printf_i_d(int n)
{
	int	i;
	int	for_count;
	int	write_val;

	i = 0;
	for_count = n;
	if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	write_val = write_i_d(n);
	if (write_val == -1)
		return (write_val);
	if (for_count < 0 && for_count > -2147483648)
	{
		for_count = for_count * -1;
		i++;
	}
	while (for_count > 9)
	{
		for_count = for_count / 10;
		i++;
	}
	i++;
	return (i);
}
