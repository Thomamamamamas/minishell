/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:34:30 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 15:21:19 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	m;

	m = 0;
	while (m < n)
	{
		if (((unsigned const char *)s)[m] == (unsigned char)c)
			return ((void *)&((unsigned const char *)s)[m]);
		m++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main()
{
	char	s[] = "pute";
	int		c = 101;
	size_t	n = 4;
	ft_memchr(s, c, n);
	return (0);
}
*/
