/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:58:55 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 15:20:28 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	n;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size == 0 || len_dest > size)
		return (len_src + size);
	n = 0;
	while (src[n] && ((len_dest + n) < size - 1))
	{
		dest[len_dest + n] = src[n];
		n++;
	}
	dest[len_dest + n] = '\0';
	return (len_src + len_dest);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int	main()
{
	char	*dest;
	char	*src;

	dest = malloc(sizeof (char) * 7);
	src = malloc(sizeof (char) * 8);
	dest[0] = 'p';
	dest[1] = 'u';
	dest[2] = 't';
	dest[3] = 'e';
	src[0] = 'p';
	src[1] = 'u';
	src[2] = 't';
	src[3] = 'a';
	src[4] = 's';
	src[5] = 's';
	src[6] = 'e';
	printf("%d\n", strlcat(dest, src, 5));
}
*/
