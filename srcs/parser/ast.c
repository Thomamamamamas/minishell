/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:50:07 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/27 14:56:04 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parser.h"

void	init_ast(t_lex *lexer, t_parser *parser)
{
	t_token	*token;
	
	parser->ast = NULL;
	parser->nb_pipes = get_nb_pipe(lexer);
	parser->actual_pipe = 0;
	if (parser->nb_pipes != 0)
	{
		token = (t_token *)malloc(sizeof(token));
		token->token = TOKEN_PIPE;
		parser->ast = create_child(NULL, token, 1);
		parser->actual_pipe = 0;
		free(token);
	}
	parser->last_pipe_ast = parser->ast;
	parser->actual = parser->ast;
}

t_ast	*create_child(t_ast *parent, t_token *token, int side)
{
	t_ast	*child;

	child = (t_ast *)malloc(sizeof(t_ast));
	if (token->token == TOKEN_EOF)
		return (NULL);
	else if (token->token == TOKEN_PIPE)
		init_ast_pipe_node(child);
	else
		init_ast_node(child, parent, token);
	if (parent && side == 0)
		parent->l_child = child;
	else if (parent && side == 1)
		parent->r_child = child;
	child->l_child = NULL;
	child->r_child = NULL;
	return (child);
}

t_ast	*create_child_pipe(t_parser *parser, t_list *lst, t_token *token)
{
	t_ast	*actual;
	int		side;

	if (parser->actual_pipe >= parser->nb_pipes - 1)
	{
		parser->actual_pipe++;
		actual = parser->last_pipe_ast;
		side = 1;
	}
	else
	{
		actual = create_child(parser->last_pipe_ast, token, 1);
		parser->last_pipe_ast = actual;
		parser->actual_pipe++;
		side = 0;
	}
	lst = lst->next;
	token = (t_token *)lst->content;
	actual = create_child(actual, token, side);
	return (actual);
}

t_ast	*init_ast_pipe_node(t_ast *child)
{
	child->type = PIPE_NODE;
	child->content = NULL;
	child->value = 0;
	return (child);
}

void	init_ast_node(t_ast *res, t_ast *parent,  t_token *token)
{
	if (token->token == TOKEN_REDIRECT)
	{
		if (!ft_strcmp(token->value, "<") || !ft_strcmp(token->value, "<<"))
			res->type = REDIRECT_INPUT_NODE;
		if (!ft_strcmp(token->value, ">") || !ft_strcmp(token->value, ">>"))
			res->type = REDIRECT_OUTPUT_NODE;
		res->content = ft_strdup(token->value);
	}
	else if (token->token == TOKEN_WORD)
	{
		if (parent == NULL|| parent->type == PIPE_NODE)
			res->type = CMD_NODE;
		else if (parent->type == REDIRECT_INPUT_NODE || parent->type == REDIRECT_OUTPUT_NODE)
			res->type = ARG_NODE;
		else if (parent->type == CMD_NODE)
			res->type = ARG_NODE;
		else
			res->type = CMD_NODE;
		res->content = ft_strdup(token->value);
	}
	else
		res->type = ERROR_NODE;
	res->value = -1;
}
