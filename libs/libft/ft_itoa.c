/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:26:29 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/04 20:59:55 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numdigit(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	getnum(int n)
{
	char	c;

	c = 0;
	while (n > 9)
		n = n % 10;
	if (n < 10)
	{
		c = n + 48;
		return (c);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*new;
	size_t	num;
	size_t	num_old;
	int		n_old;

	n_old = n;
	num = numdigit(n);
	num_old = num;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	new = malloc(sizeof(char) * (num + 1));
	if (new == NULL)
		return (NULL);
	if (n < 0)
		n = n * -1;
	while (num > 0)
	{
		new[num - 1] = getnum(n);
		num--;
		n = n / 10;
	}
	if (n_old < 0)
		new[0] = '-';
	new[num_old] = '\0';
	return (new);
}
