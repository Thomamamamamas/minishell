/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:18:19 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/19 13:19:17 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h> 
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_ptfo
{
	int	len;
	int	dot;
	int	sharp;
	int	zero_filled;
	int	r_just;
	int	l_just;
	int	r_just_value;
	int	l_just_value;
	int	p_sign;
	int	i_sign;
	int	conv;
}				t_ptfo;

int			ft_printf(const char *content, ...);

//ft_printf_utils
void		init_ptfo(t_ptfo *po);
void		write_argument(char *str, va_list arguments, t_ptfo *po);
int			write_lower_x(char *str);
int			write_argument_dot(char *str, t_ptfo *po);
int			apply_sharp(char *str, t_ptfo *po);

//ft_printf_utils2
char		*negative_str_to_positive(char *str, t_ptfo *po);
int			is_flag(char content);

//ft_printf_parser
void		handle_percent(const char *content, va_list arguments, t_ptfo *po);
void		parse_flag(const char *content, t_ptfo *po);
void		set_flags(char content, t_ptfo *po);
int			set_just_value(char content, int just_value, t_ptfo *po);
void		parse_conversion(const char *content, t_ptfo *po);

//ft_printf_conversion
char		*do_conversion(va_list arguments, t_ptfo *po);
int			conversion_is_number(int conversion);

//ft_printf_precision
int			apply_justification(char *str, t_ptfo *po, int just_type);
int			apply_p_sign(char *str, t_ptfo *po);
int			apply_i_sign(char *str, t_ptfo *po);
int			fill_with_zero(char *str, t_ptfo *po);

#endif
