/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:36:01 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/11 19:36:04 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putnbr(int n)
{
	long long int	lln;
	int				len;

	lln = n;
	len = 0;
	if (lln < 0)
	{
		ft_putchar('-');
		lln = lln * -1;
		len++;
	}
	if (lln > 9)
	{
		ft_putnbr(lln / 10);
		lln = lln % 10;
		len++;
	}
	ft_putchar(lln + '0');
	return (len++);
}
