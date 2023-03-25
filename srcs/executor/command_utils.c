/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:31:08 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/25 14:59:47 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

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

t_redirec	*get_last_cmd_redir(t_list *lst, int io)
{
	t_redirec	*redir;
	t_redirec	*res;

	res = NULL;
	while (lst)
	{
		redir = (t_redirec *)lst->content;
		if (io == 0 && redir->infile == 1)
			res = redir;
		if (io == 1 && redir->outfile == 1)
			res = redir;
	}
	return (res);
}
