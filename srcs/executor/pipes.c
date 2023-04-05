/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:14:33 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/05 16:21:34 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	command_forks(t_prog *prog)
{
	t_list	*actual_cmd;
	t_cmd	*cmd;
	int		n;
	int		res;
	int		*ids;

	res = 1;
	ids = (int *)malloc(sizeof(int) * prog->nb_cmd);
	prog->fds = pipes_2d_fd(prog);
	n = 0;
	actual_cmd = prog->cmd_list;
	ft_putstr_fd("pute\n", 2);
	while (prog->nb_cmd > 1 && n < prog->nb_cmd - 1)
	{
		cmd = (t_cmd *)actual_cmd->content;
		ids[n] = fork();
		if (ids[n] == -1)
			return (1);
		if (ids[n] == 0)
			if (wait_subprocesses(prog, n) == 0)
				execute_process(prog, cmd, n);
		n++;
		actual_cmd = actual_cmd->next;
	}
	free(ids);
	if (prog->nb_cmd > 1 && actual_cmd)
		actual_cmd = actual_cmd->next;
	if (actual_cmd)
		cmd = (t_cmd *)actual_cmd->content;
	if (wait_subprocesses(prog, n) == 0)
		res = execute_process(prog, cmd, n);
	return (res);
}

int	execute_process(t_prog *prog, t_cmd *cmd, int n)
{
	char	*path;
	int		id;

	close_unused(prog, n);
	if (dup_correct_fd(prog, n) == -1)
		exit(EXIT_FAILURE);
	path = get_correct_path(cmd, prog->path);
	ft_putstr_fd(path, 2);
	if (path == NULL || check_cmd_file_valid(path) != 0)
	{
		free(path);
		end_close_pipes(cmd, prog->fds, n);
		if (n == prog->nb_cmd - 1)
			return (-7);
		exit(EXIT_FAILURE);
	}
	id = fork();
	if (id == 0)
		execve(path, cmd->cmd, prog->envp);
	wait(NULL);
	free(path);
	end_close_pipes(cmd, prog->fds, n);
	if (n == prog->nb_cmd - 1)
		return (0);
	exit(EXIT_SUCCESS);
}
