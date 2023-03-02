/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:50:32 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/01 17:32:26 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parser.h"

t_parser	parsing(t_lex *lexer)
{
	t_parser	parser;

	check_syntax_error(lexer);
	parser = parse_line(lexer);
	return (parser);
}

int	check_syntax_error(t_lex *lexer)
{
	t_list	*actual;
	t_list	*next;

	actual = lexer->token_lst;
	while (actual)
	{
		next = actual->next;
	}
	return (0);
}

t_parser	parse_line(t_lex *lexer)
{
	t_parser	parser;
	t_list		*lst;
	t_token		*token;
	int			just_create_pipe;

	parser = init_parser(lexer);
	lst = lexer->token_lst;
	ft_printf("nb pipe = %d\n", parser.nb_pipes);
	just_create_pipe = 0;
	if (parser.nb_pipes == 0)
		lst = lst->next;
	while  (lst)
	{
		token = (t_token *)lst->content;
		if (token->token == TOKEN_PIPE)
		{
			if (parser.nb_pipes != parser.actual_pipe)
			{
				parser.actual = create_child(parser.last_pipe_ast, token, 1);
				parser.last_pipe_ast = parser.actual;
				parser.actual_pipe = parser.actual_pipe + 1;
			}
			just_create_pipe = 1;
		}
		else if (token->token != TOKEN_PIPE &&  just_create_pipe)
		{
			parser.actual = create_child(parser.actual, token, 1);
			just_create_pipe = 0;
		}
		else if (token->token != TOKEN_PIPE) 
			parser.actual = create_child(parser.actual, token, 0);
		lst = lst->next;
	}
	return (parser);
}

t_parser	init_parser(t_lex *lexer)
{
	t_token		*tmp;
	t_parser	parser;

	parser.nb_pipes = get_nb_pipe(lexer);
	parser.actual_pipe = 0;
	if (parser.nb_pipes != 0)
	{
		tmp = (t_token *)malloc(sizeof(t_token));
		tmp->token = TOKEN_PIPE;
		parser.ast = create_ast(tmp);
		parser.actual_pipe++;
		parser.actual_pipe = 1;
		parser.last_pipe_ast = &parser.ast;
		free(tmp);
	}
	else
	{
		parser.ast = create_ast((t_token *)lexer->token_lst->content);
		parser.last_pipe_ast = NULL;
	}
	parser.actual = &parser.ast;
	return (parser);
}

int	get_nb_pipe(t_lex *lexer)
{
	t_list	*lst;
	t_token	*token;
	int		res;

	lst = lexer->token_lst;
	res = 0;
	while (lst)
	{
		token = (t_token *)lst->content;
		if (token->token== TOKEN_PIPE)
			res++;
		lst = lst->next;
	}
	return (res);
}
