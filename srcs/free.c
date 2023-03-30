/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:38:48 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/30 18:47:04 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_line_utils(t_prog *prog, char *line)
{
	ft_lstclear(&prog->lexer->token_lst, &free_token);
	free(prog->lexer);
	free_ast(prog->parser->ast);
	if (prog->parser->error_value)
		free(prog->parser->error_value);
	free(prog->parser);
	free(line);
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

void	free_cmd(void *content)
{
	t_cmd		*cmd;
	t_redirec	*redirec;
	int			n;

	cmd = (t_cmd *)content;
	n = 0;
	free_2d_char(cmd->cmd);
}

void	free_2d_char(char **array)
{
	int	n;

	n = 0;
	while (array[n])
		free(array[n++]);
}
