/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:02:12 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/20 09:29:17 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(char *s)
{
	int	i;
	int	write_val;

	i = 0;
	if (s == NULL)
	{
		write_val = write(1, "(null)", 6);
		return (write_val);
	}
	while (s[i])
	{
		write_val = write (1, &s[i], 1);
		if (write_val == -1)
			return (write_val);
		i++;
	}
	return (i);
}
