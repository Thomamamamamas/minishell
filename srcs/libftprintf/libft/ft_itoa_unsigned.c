/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:39:54 by tcasale           #+#    #+#             */
/*   Updated: 2022/06/22 17:39:57 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	len(int n)
{
	int				len;
	unsigned int	nb;

	len = 1;
	if (n < 0)
		nb = n + UINT_MAX + 1;
	else
		nb = n;
	while (nb >= 10)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_unsigned(int n)
{
	unsigned int	nb;
	char			*str;
	int				i;

	if (n < 0)
		nb = n + UINT_MAX + 1;
	else
		nb = n;
	str = malloc(sizeof(char) * len(nb) + 1);
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	i = len(nb);
	str[i] = '\0';
	i--;
	while (nb > 9)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	str[i] = nb + '0';
	return (str);
}
