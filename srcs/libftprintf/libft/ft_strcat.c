/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:46:43 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/05 12:54:58 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	i = ft_strlen(dest);
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

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
	printf("%s\n", ft_strcat(dest, src));
	return (0);
}
*/
