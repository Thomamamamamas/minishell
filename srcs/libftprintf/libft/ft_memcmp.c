/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:34:38 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 15:21:26 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int			i;
	const unsigned char		*str1;
	const unsigned char		*str2;

	i = 0;
	if (s1 == s2 || n == 0)
		return (0);
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (i < n)
		{
			str1++;
			str2++;
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	char	s1[] = "pute";
	char	s2[] = "pote";
	size_t	n = 4;
	printf("%c\n", memcmp(s1, s2, n));
	return (0);
}
*/
