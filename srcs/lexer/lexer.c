/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:45:34 by tcasale           #+#    #+#             */
/*   Updated: 2023/05/04 11:12:45 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lexer.h"

void	lexing(char *line, t_lex *lexer)
{
	int		n;
	t_token	*token;

	n = 0;
	lexer->token_lst = NULL;
	while (line[n])
	{
		while (line[n] && is_space(line[n]))
			n++;
		if (line[n])
		{
			token = create_token(line, n);
			ft_lstadd_back(&lexer->token_lst, ft_lstnew(token));
			n = n + ft_strlen(token->value);
		}
	}
	token = create_token(line, n);
	ft_lstadd_back(&lexer->token_lst, ft_lstnew(token));
}

t_token	*create_token(char *line, int n)
{
	t_token	*token;
	token = (t_token *)malloc(sizeof(t_token));
	if (n == -1)
		token->value = ft_strdup("");
	else
	token->value = get_token_value(line, n);
	token->token = get_token_type(token->value);
	return (token);
}

char	*get_token_value(char *line, int start)
{
	int		end;

	end = start;
	if (line[end] == '"')
	{
		while (line[end] && line[end] != '"')
			end++;
		end++;
	}
	else if (line[end] == '|')
		return (ft_substr(line, start, end + 1 - start));
	else if (line[end] == '>' || line[end] == '<')
		end = end + len_redirection(line, line[end], end);
	else
		while (line[end] && !is_space(line[end]))
			end++;
	return (ft_substr(line, start, end - start));
}

etoken_type	get_token_type(char *value)
{
	if (!ft_strcmp(value, ""))
		return (TOKEN_EOF);
	if (!ft_strcmp(value, "<") || !ft_strcmp(value, ">") || !ft_strcmp(value, ">>") || !ft_strcmp(value, "<<"))
		return (TOKEN_REDIRECT);
	if (!ft_strcmp(value, "|"))
		return (TOKEN_PIPE);
	else
		return (TOKEN_WORD);
}
