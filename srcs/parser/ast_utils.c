/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:18:08 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/27 14:55:17 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parser.h"

void	init_ast_iteration(t_parser *parser)
{
	parser->actual = parser->ast;
	parser->actual_pipe = 0;
	if (parser->nb_pipes != 0)
		parser->last_pipe_ast = parser->actual;
}

t_ast	*get_next_cmd(t_parser *parser)
{
	while (parser->actual)
	{
		if (parser->actual->type == CMD_NODE)
			return (parser->actual);
		parser->actual = parser->actual->l_child;
	}
	return (NULL);
}

t_ast	*get_next_pipe(t_parser *parser)
{
	t_ast	*ast;

	ast = parser->last_pipe_ast;
	if (parser->actual_pipe >= parser->nb_pipes)
		return (NULL);
	while (ast && ast->type != PIPE_NODE)
		ast = ast->r_child;
	parser->last_pipe_ast = ast;
	parser->actual_pipe++;
	ast = ast->l_child;
	return (ast);
}

int	is_redirec_node(t_ast *ast)
{
	if (ast)
	{
		if (ast->type == REDIRECT_INPUT_NODE)
			return (1);
		else if (ast->type == REDIRECT_OUTPUT_NODE)
			return (1);
	}
	return (0);
}

t_ast	*get_last_redirec_node(t_ast *ast, int mode)
{
	t_ast	*last_redirec;
	t_ast	*actual;

	last_redirec = NULL;
	actual = ast;
	while (actual)
	{
		if (mode == 0 && actual->type == REDIRECT_INPUT_NODE)
			last_redirec = actual;
		else if (mode == 1 && actual->type == REDIRECT_OUTPUT_NODE)
			last_redirec = actual;
		actual = actual->l_child;
	}
	if (last_redirec)
		printf("fd = %d\n", last_redirec->value);
	return (last_redirec);
}
