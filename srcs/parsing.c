/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:14:41 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/19 14:56:00 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	parse_line(t_prog *prog, char *line)
{
	parse_cmd(prog, ft_strclear(line));
	return (0);
}

int	parse_cmd(t_prog *prog, char *line)
{
	char	**tmp;
	char	*tmp_cmd;
	int		n;

	tmp = ft_split(line, '|');
	prog->nb_cmd = 0;
	while (tmp[prog->nb_cmd])
		prog->nb_cmd++;
	prog->cmds = (t_cmd *)malloc(sizeof(t_cmd) * prog->nb_cmd);
	n = 0;
	while (n < prog->nb_cmd)
	{
		tmp_cmd = ft_strclear(tmp[n]);
		get_cmd_redirection(prog, tmp_cmd, n);
		free(tmp_cmd);
		n++;
	}
	free(line);
	ft_free_2d_char(tmp);
	return (0);
}
