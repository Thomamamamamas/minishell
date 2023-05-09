/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:00:23 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/11 20:02:58 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_puthexa_lower(long long n)
{
	char	*caracters;
	int		len;

	caracters = "0123456789abcdef";
	len = 0;
	if (n >= LONG_MAX)
		return (ft_putstr("ffffffff"));
	if (n >= 16)
	{
		len += ft_puthexa_lower(n / 16);
		len += ft_putchar(caracters[n % 16]);
	}
	else
		len += ft_putchar(caracters[n % 16]);
	return (len);
}
