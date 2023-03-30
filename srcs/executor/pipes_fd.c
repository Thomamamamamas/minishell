/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:14:37 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/30 16:44:47 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	close_unused(t_prog *prog, int i, int **fds)
{
	int	j;

	j = 0;
	while (j < prog->nb_cmd)
	{
		if (i != j)
			close(fds[j][0]);
		if (i + 1 != j)
			close(fds[j][1]);
		j++;
	}
}

void	end_close_pipes(t_cmd *cmd, int n, int **fds)
{
	t_redirec	*redir;

	close(fds[n][0]);
	close(fds[n + 1][1]);
	redir = get_last_cmd_redir(cmd->redir_list, 1);
	if (redir && redir->infile != 0)
		close(redir->infile);
	redir = get_last_cmd_redir(cmd->redir_list, 1);
	if (redir && redir->outfile != 0)
		close(redir->outfile);
}

int	**pipes_2d_fd(t_prog *prog)
{
	int	n;
	int	**fds;

	fds = ft_malloc_2d_int(2, prog->nb_cmd + 1);
	n = 0;
	while (n < prog->nb_cmd + 1)
		pipe(fds[n++]);
	return (fds);
}

int	dup_correct_fd(t_prog *prog, int **fds, int n)
{
	if (n == 0)
	{
		if (dup2(fds[1][1], 1) < 0)
			return (-1);
	}
	else if (n == prog->nb_cmd - 1)
	{
		if (dup2(fds[n][0], 0) < 0)
			return (-1);
	}
	else
	{
		if (dup2(fds[n][0], 0) < 0 || dup2(fds[n + 1][1], 1) < 0)
			return (-1);
	}
	return (0);
}

int	wait_subprocesses(t_prog *prog, int n, int **fds)
{
	int	m;
	int	*status;

	status = (int *)malloc(sizeof(int) * prog->nb_cmd);
	m = 0;
	while (m < prog->nb_cmd - n)
	{
		wait(&status[n]);
		if (WIFEXITED(status[n]))
		{
			if (WEXITSTATUS(status[n]) != EXIT_SUCCESS)
			{
				ft_free_2d_int(fds, prog->nb_cmd);
				m = status[n];
				free(status);
				return (WEXITSTATUS(m));
			}
		}
		m++;
	}
	free(status);
	return (0);
}
