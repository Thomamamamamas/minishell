/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:38:48 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/19 14:39:55 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_line(t_prog *prog, char *str)
{
	int	n;

	n = 0;
	while (n < prog->nb_cmd)
		free(prog->cmds[n++].cmd);
	free(prog->cmds);
	free(str);
}
