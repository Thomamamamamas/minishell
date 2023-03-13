/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:50:32 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/03 11:19:36 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/parser.h"

void	parsing(t_lex *lexer, t_parser *parser)
{
	parser->error_code = 0;
	check_syntax_error(lexer, parser);
	if (parser->error_code == 0)
	{
		init_parser(lexer, parser);
		parse_line(lexer, parser);
	}
}

void	check_syntax_error(t_lex *lexer, t_parser *parser)
{
	t_list	*actual;
	t_list	*next;

	actual = lexer->token_lst;
	while (actual)
	{
		next = actual->next;
		get_syntax_error(parser, actual, next);
		if (parser->error_code != 0)
			return ;
		actual = next;
	}
}

void	parse_line(t_lex *lexer, t_parser *parser)
{
	t_list		*lst;
	t_token		*token;
	int			just_create_pipe;

	lst = lexer->token_lst;
	ft_printf("nb pipe = %d\n", parser->nb_pipes);
	just_create_pipe = 0;
	if (parser->nb_pipes == 0)
		lst = lst->next;
	while  (lst)
	{
		token = (t_token *)lst->content;
		if (token->token == TOKEN_PIPE)
			just_create_pipe = 1;
		else if (token->token != TOKEN_PIPE)
		{
			ft_printf("value = %s\n", token->value);
			if (just_create_pipe)
			{
				if (parser->actual_pipe != parser->nb_pipes)
				{
					parser->actual = create_child_pipe(parser->last_pipe_ast);
					parser->last_pipe_ast = parser->actual;
					parser->actual = create_child(parser->last_pipe_ast, token, 0);
				}
				else
					parser->actual = create_child(parser->last_pipe_ast, token, 1);
				just_create_pipe = 0;
			}
			else
				parser->actual = create_child(parser->actual, token, just_create_pipe);
		}
		lst = lst->next;
	}
}

void	init_parser(t_lex *lexer, t_parser *parser)
{
	t_token		*tmp;

	parser->nb_pipes = get_nb_pipe(lexer);
	parser->actual_pipe = 0;
	if (parser->nb_pipes != 0)
	{
		tmp = (t_token *)malloc(sizeof(t_token));
		tmp->token = TOKEN_PIPE;
		parser->ast = create_ast(tmp);
		parser->actual_pipe++;
		parser->actual_pipe = 1;
		parser->last_pipe_ast = parser->ast;
		free(tmp);
	}
	else
	{
		parser->ast = create_ast((t_token *)lexer->token_lst->content);
		parser->last_pipe_ast = NULL;
	}
	parser->actual = parser->ast;
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
