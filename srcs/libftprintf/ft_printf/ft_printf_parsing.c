/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:00:16 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/15 13:16:50 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

void	handle_percent(const char *content, va_list arguments, t_ptfo *po)
{
	char	*str;

	parse_conversion(content, po);
	parse_flag(content, po);
	str = do_conversion(arguments, po);
	if (po->r_just == 1)
		po->len += apply_justification(str, po, 1);
	po->len += apply_p_sign(str, po);
	po->len += apply_i_sign(str, po);
	if (po->zero_filled == 1)
		po->len += fill_with_zero(str, po);
	if (po->sharp == 1 || po->conv == 'p')
		po->len += apply_sharp(str, po);
	write_argument(str, arguments, po);
	if (po->l_just == 1)
		po->len += apply_justification(str, po, 0);
	free(str);
}

void	parse_flag(const char *content, t_ptfo *po)
{
	int	just_value;

	just_value = 0;
	content++;
	while (*content)
	{
		if (is_flag(*content))
			set_flags(*content, po);
		else if (*content == '-')
			set_just_value(*content, just_value, po);
		else if (ft_isdigit(*content) && *content == '0' && just_value == 0)
			po->zero_filled = 1;
		else if (ft_isdigit(*content))
			just_value = set_just_value(*content, just_value, po);
		else
		{
			set_just_value(*content, just_value, po);
			return ;
		}
		content++;
	}
}

void	set_flags(char content, t_ptfo *po)
{
	if (content == '+')
		po->p_sign = 1;
	else if (content == ' ')
		po->i_sign = 1;
	else if (content == '.')
		po->dot = 1;
	else if (content == '#')
		po->sharp = 1;
}

int	set_just_value(char content, int just_value, t_ptfo *po)
{
	if (ft_isdigit(content))
	{
		just_value = just_value * 10 + content - 48;
		if (po->l_just == 1)
			po->l_just_value = just_value;
	}
	else if (content == '-')
	{
		if (just_value != 0)
			po->l_just_value = just_value;
		po->l_just = 1;
	}
	else
	{
		if (po->l_just == 0 && just_value > 0)
		{
			po->r_just_value = just_value;
			if (po->dot == 0 && po->zero_filled == 0)
				po->r_just = 1;
		}
	}
	return (just_value);
}

void	parse_conversion(const char *content, t_ptfo *po)
{
	int	first;

	first = 0;
	while (*content && (!ft_isalpha(*content) && po->conv == 0))
	{
		if (*content == '%' && first == 0)
			first++;
		else if (*content == '%' && first == 1)
			po->conv = *content;
		content++;
	}
	if ((ft_isalpha(*content) || *content == '%') && po->conv != '%')
		po->conv = *content;
}
