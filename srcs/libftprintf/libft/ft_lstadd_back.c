/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:52:49 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/06 14:54:38 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*back;

	back = *alst;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	if (!new)
		return ;
	while (back && back->next)
		back = back->next;
	back->next = new;
}
/*
#include <stdio.h>

int	main()
{
	t_list	*un;
	t_list	*deux;
	t_list	*trois;
	t_list	*quatre;
	t_list	*new;
	t_list	*last;

	un = (t_list *)malloc(sizeof(t_list));
	deux = (t_list *)malloc(sizeof(t_list));
	trois = (t_list *)malloc(sizeof(t_list));
	quatre = (t_list *)malloc(sizeof(t_list));
	new = (t_list *)malloc(sizeof(t_list));
	last = (t_list *)malloc(sizeof(t_list));
	un->next = deux;
	deux->next = trois;
	trois->next = quatre;
	quatre->next = NULL;
	quatre->content = "nul";
	new->content = "pute";
	ft_lstadd_back(&un, new);
	last = ft_lstlast(un);
	printf("%s\n", last->content);
	return (0);
}
*/
