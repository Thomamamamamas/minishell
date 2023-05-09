/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:49:48 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/02 14:58:22 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	i = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	while ((i < len_src) && (src[i]) && i < size)
	{
		dest[len_dest + i] = src[i];
		i = i + 1;
	}
	dest[len_dest + i] = '\0';
	return (dest);
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
	printf("%s\n", ft_strncat(dest, src, 5));
}
*/
