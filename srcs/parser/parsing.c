/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:50:32 by tcasale           #+#    #+#             */
/*   Updated: 2023/05/04 11:16:25 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

void	parsing(t_lex *lexer, t_parser *parser)
{
	parser->error_code = 0;
	check_syntax_error(lexer, parser);
	if (parser->error_code == 0)
		parse_line(lexer, parser);
	ft_lstclear(&lexer->token_lst, &free_token);
	free(lexer);
}

void	check_syntax_error(t_lex *lexer, t_parser *parser)
{
	t_list	*actual;
	t_list	*next;

	actual = lexer->token_lst;
	parser->error_code = 0;
	check_syntax_start(parser, actual);
	while (actual && parser->error_code == 0)
	{
		next = actual->next;
		get_syntax_error(parser, actual, next);
		actual = next;
	}
	if (parser->error_code == 0)
		parser->error_value = NULL;
}

void	parse_line(t_lex *lexer, t_parser *parser)
{
	t_list		*lst;
	t_token		*token;

	init_ast(lexer, parser);
	lst = lexer->token_lst;
	while  (lst)
	{
		token = (t_token *)lst->content;
		if (token->token == TOKEN_PIPE)
		{
			parser->actual = create_child_pipe(parser, lst, token);
			lst = lst->next;
		}
		else
			parser->actual = create_child(parser->actual, token, 0);
		if (parser->ast == NULL)
			parser->ast = parser->actual;
		lst = lst->next;
	}
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
		if (token->token == TOKEN_PIPE)
			res++;
		lst = lst->next;
	}
	return (res);
}

int	is_builtin(char *str)
{
	if (!ft_strcmp(str, "echo"))
		return (1);
	if (!ft_strcmp(str, "cd"))
		return (1);
	if (!ft_strcmp(str, "pwd"))
		return (1);
	if (!ft_strcmp(str, "export"))
		return (1);
	if (!ft_strcmp(str, "unset"))
		return (1);
	if (!ft_strcmp(str, "env"))
		return (1);
	if (!ft_strcmp(str, "exit"))
		return (1);
	return (0);
}

