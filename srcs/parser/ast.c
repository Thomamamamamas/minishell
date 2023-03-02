/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:50:07 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/01 17:32:27 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parser.h"

t_ast	create_ast(t_token *token)
{
	t_ast	res;

	if (token->token == TOKEN_PIPE)
		init_pipe_ast_node(&res);
	else
		init_first_ast_node(&res, token);
	res.l_child = NULL;
	res.r_child = NULL;
	return (res);
}

t_ast	*create_child(t_ast *parent, t_token *token, int side)
{
	t_ast	*child;

	child = malloc(sizeof(t_ast));
	if (token->token == TOKEN_PIPE)
		init_pipe_ast_node(child);
	else if (token->token == TOKEN_EOF)
		return (NULL);
	else
		init_ast_node(child, parent, token);
	child->l_child = NULL;
	child->r_child = NULL;
	if (side == 0)
		parent->l_child = child;
	else
		parent->r_child = child;
	return (child);
}

void	init_pipe_ast_node(t_ast *res)
{
	res->type = PIPE_NODE;
	res->content = NULL;
}

void	init_first_ast_node(t_ast *res, t_token *token)
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
		res->type = CMD_NODE;
		res->content = ft_strdup(token->value);
	}
	else
		res->type = ERROR_NODE;
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
		if (parent == NULL)
			res->type = CMD_NODE;
		else if (parent->type == PIPE_NODE)
			res->type = CMD_NODE;
		else
			res->type = ARG_NODE;
		res->content = ft_strdup(token->value);
	}
	else
		res->type = ERROR_NODE;
}
