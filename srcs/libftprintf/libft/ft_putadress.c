/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:47:16 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/11 22:26:02 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putadress(unsigned long long n)
{
	char	*caracters;
	int		len;

	caracters = "0123456789abcdef";
	len = 0;
	if (n >= 16)
	{
		len += ft_putnbr(n / 16);
		len += ft_putchar(caracters[n % 16]);
	}
	else
		len += ft_putchar(caracters[n % 16]);
	return (len);
}
