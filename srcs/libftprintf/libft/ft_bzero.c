/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:30:57 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 15:19:50 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n)
		ft_memset(s, '\0', n);
}
/*
#include <stdio.h>
int	main()
{
	char	s[] = "pute";
	size_t	n = 5;
	ft_bzero(s, n);
	return (0);
}
*/
