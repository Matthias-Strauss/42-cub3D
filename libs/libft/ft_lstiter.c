/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:09:08 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/05 19:09:45 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (lst)
	{
		current = lst->next;
		while (current != NULL)
		{
			f(lst->content);
			lst = current;
			current = current->next;
		}
		f(lst->content);
	}
}
