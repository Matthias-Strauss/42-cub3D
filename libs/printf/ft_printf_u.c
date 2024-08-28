/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:53:41 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/20 10:05:48 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_u(unsigned int n)
{
	char	c;
	int		write_val;

	if (n > 9)
	{
		write_val = write_u(n / 10);
		if (write_val == -1)
			return (write_val);
		write_val = write_u(n % 10);
		if (write_val == -1)
			return (write_val);
	}
	if (n < 10)
	{
		c = n + 48;
		write_val = write (1, &c, 1);
	}
	return (write_val);
}

int	ft_printf_u(unsigned int n)
{
	int				i;
	unsigned int	for_count;
	int				write_val;

	i = 0;
	for_count = n;
	write_val = write_u(n);
	if (write_val == -1)
		return (write_val);
	while (for_count > 9)
	{
		for_count = for_count / 10;
		i++;
	}
	i++;
	return (i);
}
