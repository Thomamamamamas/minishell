/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:41:29 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/28 15:02:57 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

int	dup_correct_fd(t_ast *ast)
{
	t_ast	*infile_node;
	t_ast	*outfile_node;

	infile_node = get_last_redirec_node(ast, 0);
	outfile_node= get_last_redirec_node(ast, 1);
	if (infile_node)
	{
		if (dup2(infile_node->value, 0) == -1)
			return (-1);
	}
	if (outfile_node)
	{
		if (dup2(outfile_node->value, 1) == -1)
			return (-1);
	}
	return (0);
}

void	end_close_fd(t_ast *ast)
{
	t_ast	*infile_node;
	t_ast	*outfile_node;

	infile_node = get_last_redirec_node(ast, 0);
	outfile_node= get_last_redirec_node(ast, 1);
	if (infile_node && infile_node->value >= 0)
		close(infile_node->value);
	if (outfile_node && outfile_node->value >= 0)
		close(outfile_node->value);
}
