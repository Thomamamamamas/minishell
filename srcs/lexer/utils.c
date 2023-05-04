/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:20:15 by tcasale           #+#    #+#             */
/*   Updated: 2023/05/04 11:13:09 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lexer.h"

int	len_redirection(char *line, char c, int n)
{
	if (c == '>' && line[n + 1] == '>')
		return (2);
	else if (c == '<' && line[n + 1] == '<')
		return (2);
	return (1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

