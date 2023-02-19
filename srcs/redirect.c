/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 06:00:09 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/19 14:55:59 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	get_cmd_redirection(t_prog *prog, char *cmd, int n)
{
	int		heredoc;
	char	*tmp;
	char	**tmp2d;
	char	*file;


	if (cmd[0] == '<')
	{
		if (ft_strlen(cmd) >= 2 && cmd[1] == '<')
			heredoc = 1;
		if (heredoc == 1)
			redirect_heredoc(prog, cmd, n);
		else
			redirect_infile(prog, cmd, n);
	}
}

int	redirect_heredoc(t_prog *prog, char *cmd, int n)
{
	int		still;
	char	*tmp;

	still = 1;
	while (still == 1)
	{
		if (strstart(cmd, "<") && ft_strlen(cmd) > 1)
		{
			if (tmp)
				free(tmp);
			tmp = ft_substr(cmd, 1, ft_strlen(cmd));
			free(cmd);
		}
		else
			still = 0;
	}
	if (tmp)
		free(tmp);
}

int	redirect_infile(t_prog *prog, char *cmd, int n)
{

}
