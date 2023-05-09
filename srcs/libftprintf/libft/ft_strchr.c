/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:26:15 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 15:20:53 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	n;

	n = 0;
	while (s[n])
	{
		if ((unsigned char)s[n] == (unsigned char)c)
			return ((char *)s + n);
		n++;
	}
	if ((unsigned char)s[n] == (unsigned char)c)
		return ((char *)s + n);
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char	s[] = "pupuputet";
	char	*c = "e";
	printf("%s\n", strchr(s, *c));
	printf("%s\n", ft_strchr(s, *c));
	return (0);
}
*/
