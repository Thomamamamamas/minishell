/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:50:31 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/05 10:04:38 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

void	open_all_files(t_list *cmd_list)
{
	t_list		*lst;
	t_list		*sub_lst;
	t_cmd		*cmd;

	lst = cmd_list;
	while (lst)
	{
		cmd = (t_cmd *)lst->content;
		sub_lst = cmd->redir_list;
		while (sub_lst)
		{
			open_file(sub_lst);
			t_redirec	*redirec = (t_redirec *)sub_lst->content;
			printf("%s\n", redirec->file_name);
			sub_lst = sub_lst->next;
		}
		lst = lst->next;
	}
}

void	open_file(t_list *lst)
{
	t_redirec	*redirec;

	redirec = (t_redirec *)lst->content;
	if (access(redirec->file_name, F_OK) && redirec->infile)
		redirec->fd = open(redirec->file_name, O_RDONLY);
	else
	{
		if (redirec->infile == 1)
		{
			redirec->is_invalid = 1;
			redirec->fd = -1;
		}
		else
			redirec->fd = open_outfile(redirec);
	}
}

int	open_outfile(t_redirec *redirec)
{
	if (access(redirec->file_name, F_OK))
	{
		if (redirec->append == 1)
			return (open(redirec->file_name, O_RDWR | O_APPEND));
		return (open(redirec->file_name, O_RDWR | O_TRUNC));
	}
	return (open(redirec->file_name, O_CREAT | O_RDWR, 0644));
}

int	check_files_valid(t_list *lst)
{
	t_redirec	*redirec;

	while (lst)
	{
		redirec = (t_redirec *)lst->content;
		if (redirec->is_invalid)
			return (0);
		lst = lst->next;
	}
	return (1);
}
