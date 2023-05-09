/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:57:17 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 15:35:24 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	n;
	size_t	m;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	n = 0;
	m = 0;
	while (s1[m])
	{
		str[n++] = s1[m++];
	}
	m = 0;
	while (s2[m])
	{
		str[n++] = s2[m++];
	}
	str[n] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main()
{
	char	s1[] = "bande de ";
	char	s2[] = "putes";
	char	*s;

	s = ft_strjoin(s1, s2);
	printf("%s\n", s);
	return (0);
}
*/
