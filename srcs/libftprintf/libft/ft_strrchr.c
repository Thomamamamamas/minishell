/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:59:46 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 15:21:00 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			tmp = i;
		i = i + 1;
	}
	if (s[i] == (char)c)
		return ((char *) s + i);
	if (tmp != -1)
		return ((char *)s + tmp);
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char	s[] = "pupuputeteta";
	char *c = "e";
	printf("%s\n", strrchr(s, *c));
	printf("%s\n", ft_strrchr(s, *c));
	return (0);
}
*/
