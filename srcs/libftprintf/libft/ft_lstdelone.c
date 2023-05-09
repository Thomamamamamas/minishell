/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:16:31 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/06 14:55:17 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del) (void *))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
}
/*
#include <stdio.h>

int	main()
{
	t_list	*un;

	un = (t_list *)malloc(sizeof(t_list));
	un->content = "pute";
	ft_lstdelone(un, (*del)(un->next));
	printf("%s\n", un->content);
	return (0);
}
*/
