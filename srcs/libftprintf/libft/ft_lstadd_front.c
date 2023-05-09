/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:40:09 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 15:40:11 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
/*
int	main()
{
	t_list	*first;
	t_list	*new;
	first = (t_list *)malloc(sizeof(t_list));
	new = (t_list *)malloc(sizeof(t_list));
	ft_lstadd_front(&first, new);
	return (0);
}
*/
