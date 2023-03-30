/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:17:36 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/30 15:13:00 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

t_list	*ast_to_commands(t_ast *ast, t_list *cmd_list)
{
	if (is_cmd_node(ast))
	{
		ft_lstadd_back(&cmd_list, command_node(ast));
		while (is_cmd_node(ast))
			ast = ast->l_child;
	}
	if (ast && ast->l_child)
		cmd_list = ast_to_commands(ast->l_child, cmd_list);
	if (ast && ast->r_child)
		cmd_list = ast_to_commands(ast->r_child, cmd_list);
	return (cmd_list);
}

t_list	*command_node(t_ast *ast)
{
	int		n;
	t_ast	*actual;
	t_cmd	*cmd;

	n = 0;
	actual = ast;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->cmd = (char **)malloc(sizeof(char *) * get_nb_arg_cmd(ast) + 1);
	cmd->redir_list = NULL;
	while (actual && actual->type != PIPE_NODE)
	{
		if (actual->type == REDIRECT_INPUT_NODE || actual->type == REDIRECT_OUTPUT_NODE)
		{
			cmd->redir_list = command_redirection_node(actual, cmd);
			while (actual->l_child && actual->l_child->type == ARG_NODE)
				actual = actual->l_child;
			actual = actual->l_child;
		}
		else
		{
			cmd->cmd[n++] = ft_strdup(actual->content);
			actual = actual->l_child;
		}
	}
	cmd->cmd[n] = NULL;
	return (ft_lstnew(cmd));
}

t_list	*command_redirection_node(t_ast *actual, t_cmd *cmd)
{
	t_redirec	*redirec;

	redirec = (t_redirec *)malloc(sizeof(t_redirec));
	if (actual->type == REDIRECT_INPUT_NODE)
		redirec->infile = 1;
	else
		redirec->outfile = 1;
	if (ft_strcmp(actual->content, "<<") == 0)
			redirec->heredoc = 1;
	if (ft_strcmp(actual->content, ">>") == 0)
			redirec->append = 1;
	actual = actual->l_child;
	if (actual && actual->type == ARG_NODE)
		redirec->file_name = ft_strdup(actual->content);
	ft_lstadd_back(&cmd->redir_list, ft_lstnew(redirec)); 
	return (cmd->redir_list);
}

int	is_cmd_node(t_ast *ast)
{
	if (ast)
	{
		if (ast->type == REDIRECT_INPUT_NODE || ast->type == REDIRECT_OUTPUT_NODE)
			return (1);
		if (ast->type == CMD_NODE || ast->type == ARG_NODE)
			return (1);
	}
	return (0);
}
