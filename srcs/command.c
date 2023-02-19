/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:17:36 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/19 01:33:02 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*get_correct_path(t_cmd cmd, char **env)
{
	int		n;
	char	*tmp;
	char	*actual_path;

	if (cmd.cmd[0])
	{
		if (access(cmd.cmd[0], F_OK | X_OK) == 0)
			return (cmd.cmd[0]);
	}
	n = 0;
	while (env[n] != NULL)
	{
		tmp = ft_strjoin(env[n], "/");
		actual_path = ft_strjoin(tmp, cmd.cmd[0]);
		free(tmp);
		if (access(actual_path, F_OK | X_OK) == 0)
			return (actual_path);
		free(actual_path);
		n++;
	}
	return (cmd.cmd[0]);
}

int	check_cmd_file_valid(char *file_name)
{
	if (access(file_name, F_OK) != 0)
		return (-7);
	if (access(file_name, X_OK) != 0)
		return (-5);
	return (0);
}
