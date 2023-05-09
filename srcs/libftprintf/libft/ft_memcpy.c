/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:31:52 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 15:19:59 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	m;

	if (dest == NULL && src == NULL)
		return (NULL);
	m = 0;
	while (m < n)
	{
		*((unsigned char *)dest + m) = *((unsigned char *)src + m);
		m++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main()
{
	char	dest[] = "pute";
	const char	*src = "t";
	size_t	n = 4;
	ft_memcpy(dest, src, n);
	printf("%s\n", dest);
	return (0);
}
*/
