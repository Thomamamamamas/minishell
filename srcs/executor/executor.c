/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:30:09 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/06 07:48:22 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

void	execute_line(t_prog *prog)
{
	init_ast_iteration(prog->parser);
	printf("____OPEN____\n");
	open_all_redirec_files(&prog->parser->ast);
	//open_all_files(prog->cmd_list);
	//printf("____EXECUTE____\n");
	//command_forks(prog);
	//ft_free_2d_int(prog->fds, prog->nb_cmd + 1);
	//ft_lstclear(&prog->cmd_list, &free_cmd);
}
