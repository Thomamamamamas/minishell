/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:01:48 by tcasale           #+#    #+#             */
/*   Updated: 2022/06/22 17:05:26 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*negative_str_to_positive(char *str, t_ptfo *po)
{
	int	tmp;

	tmp = ft_atoi(str) * -1;
	if (str)
		free(str);
	str = ft_itoa(tmp);
	if (tmp > 0)
		po->len += ft_putchar('-');
	return (str);
}

int	is_flag(char content)
{
	if (content == '+')
		return (1);
	else if (content == ' ')
		return (1);
	else if (content == '.')
		return (1);
	else if (content == '#')
		return (1);
	return (0);
}
