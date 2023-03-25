/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:17:36 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/25 16:55:33 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

t_list	*ast_to_commands(t_ast *ast, t_list *cmd_list)
{
	if (ast && (ast->type == REDIRECT_INPUT_NODE || ast->type == REDIRECT_OUTPUT_NODE || ast->type == CMD_NODE))
	{
		ft_lstadd_back(&cmd_list, command_node(ast));
		while (ast && (ast->type == REDIRECT_INPUT_NODE || ast->type == REDIRECT_OUTPUT_NODE || ast->type == CMD_NODE))
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
	cmd = (t_cmd *)malloc(sizeof(cmd));
	cmd->cmd = (char **)malloc(sizeof(char *) * get_nb_arg_cmd(ast) + 1);
	cmd->redir_list = NULL;
	while (actual && actual->type != PIPE_NODE)
	{
		if (actual->type == REDIRECT_INPUT_NODE || actual->type == REDIRECT_OUTPUT_NODE)
		{
			cmd->redir_list = command_redirection_node(actual, cmd);
			while (actual->l_child && actual->l_child->type == ARG_NODE)
				actual = actual->l_child;
		}
		if (actual->type == ARG_NODE || actual->type == CMD_NODE)
			cmd->cmd[n++] = ft_strdup(actual->content);
		actual = actual->l_child;
	}
	cmd->cmd[n] = NULL;
	return (ft_lstnew(cmd));
}

t_list	*command_redirection_node(t_ast *actual, t_cmd *cmd)
{
	t_redirec	*redirec;

	redirec = (t_redirec *)malloc(sizeof(t_redirec));
	if (actual->type == REDIRECT_INPUT_NODE)
	{
		if (ft_strcmp(actual->content, "<<"))
			redirec->heredoc = 1;
		redirec->infile = 1;
	}
	else
	{
		if (ft_strcmp(actual->content, ">>"))
			redirec->append = 1;
		redirec->outfile = 1;
	}
	actual = actual->l_child;
	if (actual && actual->type == ARG_NODE)
		redirec->file_name = ft_strdup(actual->content);
	printf("%d\n", redirec->infile);
	ft_lstadd_back(&cmd->redir_list, ft_lstnew(redirec)); 
	return (cmd->redir_list);
}
