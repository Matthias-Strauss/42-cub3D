/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:15:34 by kklockow          #+#    #+#             */
/*   Updated: 2023/04/06 14:12:01 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new;
	t_list	*node;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	current = lst;
	new = NULL;
	while (current != NULL)
	{
		node = ft_lstnew(f(current->content));
		if (node == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		current = current->next;
	}
	return (new);
}
