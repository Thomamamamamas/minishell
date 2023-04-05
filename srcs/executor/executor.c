/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:30:09 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/05 18:24:24 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

void	get_command_list(t_prog *prog)
{
	init_ast_iteration(prog->parser);
	prog->cmd_list = NULL;
	prog->cmd_list = ast_to_commands(prog->parser->actual, prog->cmd_list);
	prog->nb_cmd = ft_lstsize(prog->cmd_list);
}

void	execute_line(t_prog *prog)
{
	printf("____OPEN____\n");
	open_all_files(prog->cmd_list);
	printf("____EXECUTE____\n");
	//command_forks(prog);
	//ft_free_2d_int(prog->fds, prog->nb_cmd + 1);
	ft_lstclear(&prog->cmd_list, &free_cmd);
}
