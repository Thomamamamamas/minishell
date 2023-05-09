/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:34:40 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/02 15:51:38 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>

int	main()
{
	t_list	*uno;
	t_list	*dos;
	t_list	*tres;
	t_list	*quatro;
	t_list	*res;

	uno = (t_list *) malloc(sizeof(t_list));
	dos = (t_list *) malloc(sizeof(t_list));
	tres = (t_list *) malloc(sizeof(t_list));
	quatro = (t_list *) malloc(sizeof(t_list));
	res = (t_list *) malloc(sizeof(t_list));
	uno->next = dos;
	dos->next = tres;
	tres->next = quatro;
	quatro->next = NULL;
	quatro->content = "pute";
	res = ft_lstlast(uno);
	printf("%s\n", res->content);
	return (0);
}
*/
