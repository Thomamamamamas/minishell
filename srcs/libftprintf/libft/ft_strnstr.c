/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:01:37 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 15:21:34 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	char	*pt;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		pt = 0;
		if (haystack[i] == needle[0])
		{
			pt = (char *)haystack + i;
			j = 0;
			while (haystack[i + j] == needle[j] && i + j < n)
			{
				if (needle[j + 1] == '\0')
					return (pt);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	haystack[] = "pupupuputesalope";
	char	needle[] = "pute";
	printf("%s\n", ft_strnstr(haystack, needle, 4));
	return (0);
}
*/
