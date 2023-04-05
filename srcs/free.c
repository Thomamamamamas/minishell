/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:38:48 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/05 18:19:50 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_line_utils(char *line)
{
	if (line)
		free(line);
}

void	free_lexer(t_prog *prog)
{
	ft_lstclear(&prog->lexer->token_lst, &free_token);
	free(prog->lexer);
}

void	free_parser(t_prog *prog)
{
	free_ast(prog->parser->ast);
	if (prog->parser->error_value)
		free(prog->parser->error_value);
	free(prog->parser);
}

void	free_2d_char(char **array)
{
	int	n;

	n = 0;
	while (array[n])
	{
		if (array[n])
			free(array[n]);
		n++;
	}
}

void	free_token(void *token)
{
	t_token	*actual;

	actual = (t_token *)token;
	if (actual->value)
		free(actual->value);
	free(actual);
}

void	free_ast(t_ast *ast)
{
	if (ast->l_child)
		free_ast(ast->l_child);
	if (ast->r_child)
		free_ast(ast->r_child);
	if (ast)
	{
		if (ast->content)
			free(ast->content);
		free(ast);
	}
}
