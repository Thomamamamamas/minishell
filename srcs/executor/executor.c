/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:30:09 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/31 18:22:48 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

void	execute_line(t_prog *prog)
{
	t_list	*cmd_list;

	init_ast_iteration(prog->parser);
	cmd_list = NULL;
	cmd_list = ast_to_commands(prog->parser->actual, cmd_list);
	print_cmds(cmd_list);
	printf("____OPEN____\n");
	open_all_files(cmd_list);
	printf("____EXECUTE____\n");
	ft_lstclear(&cmd_list, &free_cmd);
}
