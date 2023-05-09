/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:01:36 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/15 13:08:12 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

void	init_ptfo(t_ptfo *po)
{
	po->sharp = 0;
	po->dot = 0;
	po->zero_filled = 0;
	po->r_just = 0;
	po->r_just_value = 0;
	po->l_just = 0;
	po->l_just_value = 0;
	po->p_sign = 0;
	po->i_sign = 0;
	po->conv = 0;
}

void	write_argument(char *str, va_list arguments, t_ptfo *po)
{
	if (po->conv == 'c')
		po->len += ft_putchar(va_arg(arguments, int));
	else if (po->conv == 'x' && po->dot == 0)
		po->len += write_lower_x(str);
	else if (po->conv == '%')
		po->len += ft_putchar('%');
	else if (po->dot == 1)
	{
		po->len += write_argument_dot(str, po);
	}
	else
		po->len += ft_putstr(str);
}

int	write_lower_x(char *str)
{
	int	n;
	int	len;

	n = 0;
	len = 0;
	while (str[n])
	{
		if (ft_isalpha(str[n]))
			len += ft_putchar(ft_tolower(str[n]));
		else
			len += ft_putchar(str[n]);
		n++;
	}
	return (len);
}

int	write_argument_dot(char *str, t_ptfo *po)
{
	int	n;
	int	len;

	n = 0;
	len = 0;
	if (po->conv == 's')
		while (str[n] && n < po->r_just_value)
			len += ft_putchar(str[n++]);
	else if (conversion_is_number(po->conv))
	{
		if (ft_atoi(str) < 0 && po->conv != 'u')
			str = negative_str_to_positive(str, po);
		len += fill_with_zero(str, po);
		if (po->conv == 'x')
			len += write_lower_x(str);
		else
			len += ft_putstr(str);
	}
	return (len);
}

int	apply_sharp(char *str, t_ptfo *po)
{
	if (*str != '0' || po->conv == 'p')
	{
		if (po->conv == 'x' || po->conv == 'p')
			return (ft_putstr("0x"));
		else if (po->conv == 'X')
			return (ft_putstr("0X"));
	}
	return (0);
}
