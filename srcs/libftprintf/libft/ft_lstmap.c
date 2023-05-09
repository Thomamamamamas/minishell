/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:47:47 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/06 14:53:04 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*save;

	if (!lst || !f)
		return (NULL);
	save = NULL;
	new_list = NULL;
	while (lst)
	{
		new_list = ft_lstnew(f(lst->content));
		if (!new_list)
		{
			if (!del)
			{
				del(new_list->content);
				free(new_list);
				new_list = NULL;
				ft_lstclear(&save, del);
			}
			return (NULL);
		}
		ft_lstadd_back(&save, new_list);
		lst = lst->next;
	}
	return (save);
}
