/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:45:34 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/23 19:45:53 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lexer.h"

void	lexing(char *line, t_lex *lexer)
{
	int		len;
	int		n;

	n = 0;
	len = 0;
	lexer->len = get_nb_of_tokens(line);
	printf("%d\n", lexer->len);
	lexer->tokens = (t_token *)malloc(sizeof(t_token) * lexer->len);
	while (len < lexer->len - 1)
	{
		while (line[n] && is_space(line[n]))
			n++;
		if (line[n])
		{
			lexer->tokens[len].value = get_token_value(line, n);
			printf("pute = %s\n", lexer->tokens[len].value);
			lexer->tokens[len].token = get_token_type(lexer->tokens[len].value);
			n = n + ft_strlen(lexer->tokens[len].value);
			len = len + 1;
		}
	}
	lexer->tokens[len].value = "";
	lexer->tokens[len].token = get_token_type(lexer->tokens[len].value);
}

int	get_nb_of_tokens(char *str)
{
	int	n;
	int	res;

	n = 0;
	res = 0;
	while (str[n])
	{
		if (str[n] == '"')
		{
			res++;
			n++;
			while (str[n] && str[n] != '"')
				n++;
			n++;
		}
		else if (str[n] && !is_space(str[n]) && str[n] != '"')
		{
			res++;
			while (str[n] && (!is_space(str[n]) && str[n] != '"'))
				n++;
		}
		else
			n++;
	}
	return (res + 1);
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
