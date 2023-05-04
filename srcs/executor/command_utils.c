/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:31:08 by tcasale           #+#    #+#             */
/*   Updated: 2023/05/04 09:18:08 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

int	get_cmd_len(t_ast *ast)
{
	int	n;

	if (!ast)
		return (0);
	if (ast->type != CMD_NODE)
		return (0);
	n = 1;
	ast = ast->l_child;
	while (ast && ast->type == ARG_NODE)
	{
		n++;
		ast = ast->l_child;
	}
	return (n);
}

char	*get_correct_path(t_ast *ast, char **env)
{
	int		n;
	char	*tmp;
	char	*actual_path;

	if (ast->content)
	{
		if (access(ast->content, F_OK | X_OK) == 0)
			return (ast->content);
	}
	n = 0;
	while (env[n] != NULL)
	{
		tmp = ft_strjoin(env[n], "/");
		actual_path = ft_strjoin(tmp, ast->content);
		free(tmp);
		if (access(actual_path, F_OK | X_OK) == 0)
			return (actual_path);
		free(actual_path);
		n++;
	}
	return (ast->content);
}

int	check_cmd_file_valid(char *file_name)
{
	if (file_name == NULL)
		return (1);
	if (access(file_name, F_OK) != 0)
		return (1);
	if (access(file_name, X_OK) != 0)
		return (1);
	return (0);
}

char	**create_cmd_from_ast(t_ast *ast)
{
	char	**cmd;
	int		len;
	int		n;

	n = 0;
	len = get_cmd_len(ast);
	cmd = (char **)malloc(sizeof(char *) * len + 1);
	while (ast && (ast->type == CMD_NODE || ast->type == ARG_NODE))
	{
		cmd[n++] = ft_strdup(ast->content);
		ast = ast->l_child;
	}
	cmd[n] = NULL;
	return (cmd);
}
