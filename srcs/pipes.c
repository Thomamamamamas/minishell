/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:14:33 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/23 14:51:56 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	pipes_fork(t_prog *prog)
{
	int	n;
	int	res;
	int	*ids;
	int	**fds;

	res = 1;
	ids = (int *)malloc(sizeof(int) * prog->nb_cmd);
	fds = pipes_2d_fd(prog);
	n = 0;
	while (n < prog->nb_cmd - 1)
	{
		ids[n] = fork();
		if (ids[n] == -1)
			return (1);
		if (ids[n] == 0)
			if (wait_subprocesses(prog, n, fds) == 0)
				pipes_process(prog, n, fds);
		n++;
	}
	free(ids);
	if (wait_subprocesses(prog, n, fds) == 0)
		res = pipes_process(prog, n, fds);
	ft_free_2d_int(fds, prog->nb_cmd + 1);
	return (res);
}

int	pipes_process(t_prog *prog, int n, int **fds)
{
	char	*path;
	int		id;

	close_unused(prog, n, fds);
	if (dup_correct_fd(prog, fds, n) == -1)
		exit(EXIT_FAILURE);
	path = get_correct_path(prog->cmds[n], prog->path);
	if (path == NULL || check_cmd_file_valid(path) != 0)
	{
		free(path);
		end_close_pipes(&prog->cmds[n], n, fds);
		if (n == prog->nb_cmd - 1)
			return (-7);
		exit(EXIT_FAILURE);
	}
	id = fork();
	if (id == 0)
		execve(path, prog->cmds[n].cmd, prog->envp);
	wait(NULL);
	free(path);
	end_close_pipes(&prog->cmds[n], n, fds);
	if (n == prog->nb_cmd - 1)
		return (0);
	exit(EXIT_SUCCESS);
}

int	pipe_error_management(t_prog *prog, int code)
{
	if (code == 1)
		ft_putstr_fd("Error : Pipe error\n",2); 
	if (code == 2)
		ft_putstr_fd("Error : Dup error\n",2); 
	prog->error = code;
	return (code);
}
