/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:38:48 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/01 14:12:20 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_line_utils(t_lex *lexer, char *line)
{
	ft_lstclear(&lexer->token_lst, &free_token);
	free(line);
}

void	free_token(void *token)
{
	t_token	*actual;

	actual = (t_token *)token;
	if (actual->value)
		free(actual->value);
	free(actual);
}
