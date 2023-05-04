/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:41:29 by tcasale           #+#    #+#             */
/*   Updated: 2023/05/02 11:03:55 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

int	dup_correct_fd(t_prog *prog, t_ast *ast)
{
	t_ast	*infile_node;
	t_ast	*outfile_node;

	infile_node = get_last_redirec_node(ast, 0);
	outfile_node= get_last_redirec_node(ast, 1);
	if (infile_node)
	{
		prog->fd_stdin = dup(0);
		if (dup2(infile_node->value, 0) == -1)
			return (-1);
	}
	if (outfile_node)
	{
		prog->fd_stdout = dup(1);
		if (dup2(outfile_node->value, 1) == -1)
			return (-1);
	}
	return (0);
}

int	redup_correct_fd(t_prog *prog, t_ast *ast)
{
	t_ast	*infile_node;
	t_ast	*outfile_node;

	infile_node = get_last_redirec_node(ast, 0);
	outfile_node = get_last_redirec_node(ast, 1);
	if (infile_node)
	{
		if (dup2(prog->fd_stdin, 0) == -1)
			return (-1);
		close(prog->fd_stdin);
	}
	if (outfile_node)
	{
		if (dup2(prog->fd_stdout, 1) == -1)
			return (-1);
		close(prog->fd_stdout);
	}
	return (0);
}
