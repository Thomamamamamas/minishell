/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:38:48 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/29 21:27:24 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_parser(t_prog *prog)
{
	free_ast(prog->parser->ast);
	if (prog->parser->error_code != 0 && prog->parser->error_value != NULL)
		free(prog->parser->error_value);
	free(prog->parser);
}

void	free_2d_char(char **array)
{
	int	n;

	n = 0;
	if (array != NULL)
	{
		while (array[n] != NULL)
			free(array[n++]);
		free(array);
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
	if (ast != NULL)
	{
		if (ast->l_child != NULL)
			free_ast(ast->l_child);
		if (ast->r_child != NULL)
			free_ast(ast->r_child);
		if (ast->content != NULL)
			free(ast->content);
		free(ast);
	}
}
