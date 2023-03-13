/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:23:44 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/19 14:28:04 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/minishell.h"

int	blank_line(char *line)
{
	int	n;

	n = 0;
	while (line[n] && (line[n] == ' ' || line[n] == '\t'))
		n++;
	if (n == ft_strlen(line))
		return (1);
	return (0);
}
