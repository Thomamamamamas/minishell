/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:32:51 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/02 14:32:56 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void *src, int c, size_t n)
{
	unsigned int	m;
	unsigned char	*dest2;
	unsigned char	*src2;

	m = 0;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	while (m < n)
	{
		*dest2 = *src2;
		if (*src2 == (unsigned char)c)
			return (dest2 + 1);
		m++;
		dest2++;
		src2++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main()
{
	char	dest[] = "peta";
	char	src[] = "saupa";
	int		c = 101;
	size_t	n = 4;
	ft_memccpy(dest, src, c, n);
	printf("%s\n", dest);
	return (0);
}
*/
