/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:14:48 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/05 18:01:42 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (*lst)
	{
		current = (*lst)->next;
		while (current != NULL)
		{
			del((*lst)->content);
			free(*lst);
			*lst = current;
			current = current->next;
		}
		del((*lst)->content);
		free(*lst);
		*lst = NULL;
	}
}
