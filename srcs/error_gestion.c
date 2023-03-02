/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:38:10 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/02 18:44:14 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	parsing_error_gestion(t_parser *parser)
{
	if (parser->error_code == SYNTAX_ERROR)
	{
		ft_putstr_fd("syntax error near unexpected token : ", 2);
		ft_putstr_fd(parser->error_value, 2);
		ft_putstr_fd("\n", 2);
	}
}
