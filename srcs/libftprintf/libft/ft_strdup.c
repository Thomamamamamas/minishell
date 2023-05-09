/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:38:27 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/17 15:25:14 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*res;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc(sizeof(*s) * len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main()
{
	char	s[] = "pute";

	printf("%s\n", ft_strdup(s));
	return (0);
}
*/
