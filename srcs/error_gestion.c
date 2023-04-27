/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:38:10 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/27 14:58:05 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	parsing_error_gestion(t_parser *parser)
{
	if (parser->error_code == 0)
		return ;
	if (parser->error_code == SYNTAX_ERROR)
		ft_putstr_fd("parse error near ", 2);
	ft_putstr_fd(parser->error_value, 2);
	ft_putstr_fd("\n", 2);
}

int		exec_error_gestion(int error_code, char *error_value)
{
	if (error_code == 1)
		ft_putstr_fd("Dup error", 2);
	if (error_code == 2)
	{
		ft_putstr_fd("Command doesn't exist: ", 2);
		ft_putstr_fd(error_value, 2);
	}
	ft_putstr_fd("\n", 2);
	return (EXIT_FAILURE);
}

void	error_gestion(t_prog *prog)
{
	if (prog->error_code == 0)
		return ;
	if (prog->error_code == 1)
		ft_putstr_fd("No such file or directory: ", 2);
	else if (prog->error_code == 2)
		ft_putstr_fd("Permission denied: ", 2);
	ft_putstr_fd(prog->error_value, 2);
	ft_putstr_fd("\n", 2);
}
