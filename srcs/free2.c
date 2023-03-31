/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:26:45 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/31 12:31:02 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_cmd(void *content)
{
	t_cmd		*cmd;
	int			n;

	cmd = (t_cmd *)content;
	n = 0;
	free_2d_char(cmd->cmd);
	ft_lstclear(&cmd->redir_list, &free_redirec);
}

void	free_redirec(void *content)
{
	t_redirec	*redirec;

	redirec = (t_redirec *)content;
	if (redirec->file_name)
		free(redirec->file_name);
	free(redirec);
}

