/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:21:09 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/06 14:34:47 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	lln;

	lln = n;
	if (lln < 0)
	{
		ft_putchar_fd('-', fd);
		lln = lln * -1;
	}
	if (lln > 9)
	{
		ft_putnbr_fd(lln / 10, fd);
		lln = lln % 10;
	}
	ft_putchar_fd(lln + '0', fd);
}
/*
int	main()
{
	ft_putnbr_fd(-42099, 1);
	return (0);
}
*/
