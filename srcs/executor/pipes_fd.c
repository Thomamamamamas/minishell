/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:14:37 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/09 15:25:43 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	close_unused(t_prog *prog, int i)
{
	int		j;
	int		tmp_actual_pipe;
	t_ast	*tmp_last_pipe_ast;
	t_ast	*ast;

	j = 0;
	tmp_actual_pipe = prog->parser->actual_pipe;
	ast = prog->parser->ast;
	tmp_last_pipe_ast = ast;
	while (j < prog->parser->nb_pipes)
	{
		if (i != j)
			close(prog->fds[j][0]);
		if (i + 1 != j)
			close(prog->fds[j][1]);
		while (prog->parser->actual_pipe != prog->parser->nb_pipes && ast)
		{
			if (i != tmp_actual_pipe && ast && (ast->type == REDIRECT_INPUT_NODE || ast->type == REDIRECT_OUTPUT_NODE))
			{
				if (ast->value != -1)
					close(ast->value);
			}
			ast = ast->l_child;
		}
		ast = get_next_pipe(prog->parser);
		j++;
	}
	prog->parser->actual_pipe = tmp_actual_pipe;
	prog->parser->last_pipe_ast = tmp_last_pipe_ast;
}

void	end_close_pipes(t_ast *ast, int **fds, int n)
{
	close(fds[n][0]);
	close(fds[n + 1][1]);
	while (ast)
	{
		if ((ast->type == REDIRECT_INPUT_NODE || ast->type == REDIRECT_OUTPUT_NODE) && ast->value != -1)
			close(ast->value);
		ast = ast->l_child;
	}
}

int	**pipes_2d_fd(t_prog *prog)
{
	int	n;
	int	**fds;

	fds = ft_malloc_2d_int(2, prog->parser->nb_pipes + 1);
	n = 0;
	while (n < prog->parser->nb_pipes + 1)
		pipe(fds[n++]);
	return (fds);
}

int	dup_correct_fd(t_prog *prog, t_ast *ast, int n)
{
	t_ast	*infile_node;
	t_ast	*outfile_node;

	infile_node = get_last_redirec_node(ast, 0);
	outfile_node = get_last_redirec_node(ast, 1);
	if (n == prog->parser->nb_pipes)
	{
		if (dup2(prog->fds[n][0], 0) < 0)
			return (-1);
	}
	else if (n == prog->parser->nb_pipes)
	{
		if (dup2(prog->fds[1][1], 1) < 0)
			return (-1);
	}
	else
	{
		if (dup2(prog->fds[n][0], 0) < 0 || dup2(prog->fds[n + 1][1], 1) < 0)
			return (-1);
	}
	return (0);
}

int	wait_subprocesses(t_prog *prog, int n)
{
	int	m;
	int	*status;

	status = (int *)malloc(sizeof(int) * prog->parser->nb_pipes);
	m = 0;
	while (m < prog->nb_cmd - n)
	{
		wait(&status[n]);
		if (WIFEXITED(status[n]))
		{
			if (WEXITSTATUS(status[n]) != EXIT_SUCCESS)
			{
				ft_free_2d_int(prog->fds, prog->parser->nb_pipes);
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
