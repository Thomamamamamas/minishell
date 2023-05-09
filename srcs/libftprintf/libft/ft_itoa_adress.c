/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_adress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:39:08 by tcasale           #+#    #+#             */
/*   Updated: 2022/06/22 18:41:03 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	size_to_allocate(unsigned long long n)
{
	int	len;

	len = 0;
	while (n / 16 != 0)
	{
		n = n / 16;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa_adress(unsigned long long n)
{
	char	*caracters;
	int		len;
	int		i;
	char	*str;

	len = size_to_allocate(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	caracters = "0123456789abcdef";
	str[len] = '\0';
	i = len - 1;
	if (n == 0)
		str[i] = '0';
	while (n != 0)
	{
		str[i] = caracters[n % 16];
		n = n / 16;
		i--;
	}
	return (str);
}
