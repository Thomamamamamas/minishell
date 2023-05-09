/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:10:49 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 15:20:18 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	n;

	if (!dest || !src || !size)
		return (ft_strlen(src));
	n = 0;
	while ((n < (size - 1)) && src[n])
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = 0;
	return (ft_strlen(src));
}
/*
#include <stdio.h>

int	main()
{
	char	*dest;
	char	*src;
	size_t	size;

	size = 7;
	dest = malloc(sizeof(char) * size);
	src = malloc(sizeof(char) * 5);
	dest[0] = 'p';
	dest[1] = 'u';
	src[0] = 's';
	src[1] = 'u';
	src[2] = 'c';
	src[3] = 'e';
	printf("%zu\n", ft_strlcpy(dest, src, size));
	printf("%s\n", dest);
	return (0);
}
*/
