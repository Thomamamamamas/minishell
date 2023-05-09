/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:17:23 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/15 13:08:58 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *content, ...)
{
	t_ptfo	po;
	va_list	arguments;

	va_start(arguments, content);
	po.len = 0;
	while (*content)
	{
		if (*content == '%')
		{
			init_ptfo(&po);
			handle_percent(content, arguments, &po);
			content++;
			while (*content && *content != po.conv)
				content++;
		}
		else
			po.len += ft_putchar(*content);
		content++;
	}
	va_end(arguments);
	return (po.len);
}
