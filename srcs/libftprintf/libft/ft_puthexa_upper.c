/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:52:30 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/11 20:04:25 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_puthexa_upper(long long n)
{
	char	*caracters;
	int		len;

	caracters = "0123456789ABCDEF";
	len = 0;
	if (n >= LONG_MAX)
		return (ft_putstr("FFFFFFFF"));
	if (n >= 16)
	{
		len += ft_puthexa_upper(n / 16);
		len += ft_putchar(caracters[n % 16]);
	}
	else
		len += ft_putchar(caracters[n % 16]);
	return (len);
}
