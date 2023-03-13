/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 10:31:01 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/13 05:26:25 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	print_cmds(t_list *cmd_list)
{
	t_list		*actual_cmd;
	t_list		*actual_redirec;
	t_cmd		*cmd;
	t_redirec	*redirec;
	int		n;

	actual_cmd = cmd_list;
	ft_printf("__________COMMAND___________\n");
	while (actual_cmd)
	{
		n = 1;
		cmd = (t_cmd *)actual_cmd->content;
		ft_printf("CMD : %s", cmd->cmd[0]);
		while (cmd->cmd[n])
		{
			ft_printf(" %s", cmd->cmd[n]);
			n++;
		}
		ft_printf("\n");
		actual_redirec = cmd->redir_list;
		ft_printf("%d\n", ft_lstsize(actual_redirec));
		while (actual_redirec)
		{
			redirec = (t_redirec *)actual_redirec->content;
			if (redirec->heredoc == 1)
				ft_printf("\t<< ");
			else if (redirec->infile == 1)
				ft_printf("\t<< ");
			else if (redirec->outfile == 1)
				ft_printf("\t> ");
			else if (redirec->append == 1)
				ft_printf("\t>> ");
			ft_printf("pute\n");
			ft_printf("%s\n", redirec->file_name);
			actual_redirec = actual_redirec->next;
		}
		actual_cmd = actual_cmd->next;
	}
}
