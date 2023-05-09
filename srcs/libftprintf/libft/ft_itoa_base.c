/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:39:31 by tcasale           #+#    #+#             */
/*   Updated: 2022/06/22 17:39:33 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static size_t	size_to_allocate(long long n, size_t base)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n / base > 0)
	{
		n = n / base;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa_base(long long n, size_t base)
{
	char	*caracters;
	size_t	len;
	char	*str;

	len = size_to_allocate(n, base);
	if (n >= LONG_MAX)
		return ("FFFFFFFF");
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str || base > 16)
		return (NULL);
	caracters = "0123456789ABCDEF";
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[len--] = caracters[n % base];
		n = n / base;
	}
	return (str);
}
/*
#include <stdio.h>

int	main()
{
	printf("%s\n", ft_itoa_base(-42, 16));
	return (0);
}
*/
