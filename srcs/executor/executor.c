/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:30:09 by tcasale           #+#    #+#             */
/*   Updated: 2023/05/04 09:18:07 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

void	execute_line(t_prog *prog)
{
	prog->error_code = 0;
	prog->error_value = NULL;
	open_all_redirec_files(prog, prog->parser->ast);
	check_files_valid(prog, prog->parser->ast);
	if (prog->error_code != 0)
		return ;
	//printf("____EXECUTE____\n");
	init_ast_iteration(prog->parser);
	if (prog->parser->nb_pipes == 0)
		execute_single_cmd(prog);
	else
		command_forks(prog);
}

int	execute_single_cmd(t_prog *prog)
{
	t_ast	*actual;
	char	*path;
	char	**cmd;
	int		id;

	actual = get_next_cmd(prog->parser);
	if (dup_correct_fd(prog, prog->parser->ast) == -1)
		return (exec_error_gestion(1, NULL));
	path = get_correct_path(actual, prog->path);
	if (path == NULL || check_cmd_file_valid(path) != 0)
	{
		close_all_redirec_files(prog->parser->ast);
		exec_error_gestion(2, path);
		if (path)
			free(path);
		return (2);
	}
	cmd = create_cmd_from_ast(actual);
	id = fork();
	if (id == 0)
	{
		execve(path, cmd, prog->envp);
		exit(EXIT_FAILURE);
	}
	wait(NULL);
	free(path);
	free_2d_char(cmd);
	redup_correct_fd(prog, prog->parser->ast);
	close_all_redirec_files(prog->parser->ast);
	return (0);
}

void	execute_multi_cmd(t_prog *prog)
{
	command_forks(prog);
}
