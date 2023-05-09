/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:40:22 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 15:40:23 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n;

	n = 0;
	while (lst)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}

/*
int	main()
{
	t_list	*first;
	t_list	*deuz;
	t_list *tres;
	t_list *four;
	t_list *five;
	t_list *six;

	first = (t_list *) malloc(sizeof(t_list));
	deuz = (t_list *) malloc(sizeof(t_list));
	tres = (t_list *) malloc(sizeof(t_list));
	four = (t_list *) malloc(sizeof(t_list));
	five = (t_list *) malloc(sizeof(t_list));
	six = (t_list *) malloc(sizeof(t_list));
	first->next = deuz;
	deuz->next = tres;
	tres->next = four;
	four->next = five;
	five->next = six;
	six->next = NULL;
	printf("%d\n", ft_lstsize(first));
	return (0);
}
*/
