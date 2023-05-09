/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:42:18 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/11 20:03:50 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putnbr_unsigned(int n)
{
	unsigned int	nb;
	int				len;

	len = 0;
	if (n < 0)
	{
		nb = n + UINT_MAX + 1;
	}
	else
		nb = n;
	if (nb > 9)
	{
		len += ft_putnbr_unsigned(nb / 10);
		nb = nb % 10;
	}
	len += ft_putchar(nb + '0');
	return (len);
}
