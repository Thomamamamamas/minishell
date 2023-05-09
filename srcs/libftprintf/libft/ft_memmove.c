/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:34:01 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 15:23:24 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	m;

	if (src == dest)
		return (dest);
	m = 0;
	if (src < dest)
	{
		m = n;
		while (m-- > 0)
		{
			*(unsigned char *)(dest + m) = *(unsigned char *)(src + m);
		}
	}
	else
	{
		while (m < n)
		{
			*(unsigned char *)(dest + m) = *(unsigned char *)(src + m);
			m++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>

int	main()
{
	char		dest[] = "pute";
	const char	src[] = "sale";
	size_t		n = 4;
	printf("%s\n", dest);
	ft_memmove(dest, src, n);
	printf("%s\n", dest);
	return (0);
}
*/
