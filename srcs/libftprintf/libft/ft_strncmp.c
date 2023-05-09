/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:02:59 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 15:21:12 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	cmp_1;
	unsigned char	cmp_2;

	i = 0;
	if (!n)
		return (n);
	cmp_1 = (unsigned char)s1[i];
	cmp_2 = (unsigned char)s2[i];
	while ((cmp_1 && cmp_2) && (i < n))
	{
		cmp_1 = (unsigned char)s1[i];
		cmp_2 = (unsigned char)s2[i];
		if (cmp_1 != cmp_2)
			return (cmp_1 - cmp_2);
		i++;
	}
	return (cmp_1 - cmp_2);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	s1[] = "putes";
	char	s2[] = "putez";
	size_t	n = 5;
	printf("%d\n", strncmp(s1, s2, n));
	printf("%d\n", ft_strncmp(s1, s2, n));
	return (0);
}
*/
