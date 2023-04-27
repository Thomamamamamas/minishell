/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:14:33 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/27 12:34:52 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	command_forks(t_prog *prog)
{
	t_ast	*actual;
	int		n;
	int		res;
	int		*ids;

	res = 1;
	ids = (int *)malloc(sizeof(int) * prog->parser->nb_pipes);
	prog->fds = pipes_2d_fd(prog);
	n = 0;
	actual = prog->parser->ast;
	while (actual && n < prog->parser->nb_pipes - 1)
	{
		ids[n] = fork();
		if (ids[n] == -1)
			return (1);
		if (ids[n] == 0)
			if (wait_subprocesses(prog, n) == 0)
				execute_process(prog, actual, n);
		actual = get_next_pipe(prog->parser);
		n++;
	}
	free(ids);
	actual = get_next_pipe(prog->parser);
	if (wait_subprocesses(prog, n) == 0)
		res = execute_process(prog, actual, n);
	return (res);
}

int	execute_process(t_prog *prog, t_ast *ast, int n)
{
	char	*path;
	int		id;

	printf("try close unused\n");
	close_unused_multi(prog, n);
	printf("close unused\n");
	if (dup_correct_fd_multi(prog, ast, n) == -1)
		exit(EXIT_FAILURE);
	printf("dup correct fd\n");
	path = get_correct_path(ast, prog->path);
	printf("get correct path\n");
	ft_putstr_fd(path, 2);
	if (path == NULL || check_cmd_file_valid(path) != 0)
	{
		free(path);
		end_close_fd_multi(ast, prog->fds, n);
		if (n == prog->nb_cmd - 1)
			return (-7);
		exit(EXIT_FAILURE);
	}
	id = fork();
	if (id == 0)
		execve(path, &ast->content, prog->envp);
	wait(NULL);
	free(path);
	end_close_fd_multi(ast, prog->fds, n);
	if (n == prog->parser->nb_pipes - 1)
		return (0);
	exit(EXIT_SUCCESS);
}
