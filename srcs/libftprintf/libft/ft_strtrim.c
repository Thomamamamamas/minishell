/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:26:14 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/28 12:26:18 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	char_is_in_set(const char c, const char *set)
{
	int	n;

	n = 0;
	while (set[n])
	{
		if (set[n] == c)
			return (1);
		n++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	n;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && char_is_in_set(s1[start], set) == 1)
		start++;
	while (end > start && char_is_in_set(s1[end - 1], set) == 1)
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	n = 0;
	while (start < end)
	{
		str[n] = s1[start];
		n++;
		start++;
	}
	str[n] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main()
{
	char	s1[] = "1test2";
	char	set[] = "12";
	char	*str;

	str = ft_strtrim(s1, set);
	printf("%s\n", str);
	return (0);
}
*/
