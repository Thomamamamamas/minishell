/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:17:36 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/13 05:26:26 by tcasale          ###   ########.fr       */
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
	t_list	*res;
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
			ft_printf("proute\n");
			cmd->redir_list = command_redirection_node(actual, cmd);
		}
		if (actual->type == ARG_NODE || actual->type == CMD_NODE)
		{
			cmd->cmd[n] = ft_strdup(actual->content);
			n++;
		}
		actual = actual->l_child;
	}
	cmd->cmd[n] = NULL;
	res = ft_lstnew(cmd);
	return (res);
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
	if (actual && actual->type == CMD_NODE)
		redirec->file_name = ft_strdup(actual->content);
	ft_lstadd_back(&cmd->redir_list, ft_lstnew(redirec)); 
	return (cmd->redir_list);
}

int	get_nb_arg_cmd(t_ast *ast)
{
	int	n;

	n = 1;
	while (ast)
	{
		ast = ast->l_child;
		if (ast && ast->type == ARG_NODE)
			n++;
		else
			return (n);
	}
	return (n);
}


char	*get_correct_path(t_cmd cmd, char **env)
{
	int		n;
	char	*tmp;
	char	*actual_path;

	if (cmd.cmd[0])
	{
		if (access(cmd.cmd[0], F_OK | X_OK) == 0)
			return (cmd.cmd[0]);
	}
	n = 0;
	while (env[n] != NULL)
	{
		tmp = ft_strjoin(env[n], "/");
		actual_path = ft_strjoin(tmp, cmd.cmd[0]);
		free(tmp);
		if (access(actual_path, F_OK | X_OK) == 0)
			return (actual_path);
		free(actual_path);
		n++;
	}
	return (cmd.cmd[0]);
}

int	check_cmd_file_valid(char *file_name)
{
	if (access(file_name, F_OK) != 0)
		return (-7);
	if (access(file_name, X_OK) != 0)
		return (-5);
	return (0);
}
