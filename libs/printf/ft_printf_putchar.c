/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:03:42 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/20 09:25:56 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putchar(int i, const char *format_string)
{
	int	write_val;

	write_val = write(1, &format_string[i], 1);
	return (write_val);
}
