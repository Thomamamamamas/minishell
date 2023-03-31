/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:13:14 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/31 15:16:42 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parser.h"

void	get_syntax_error(t_parser *parser, t_list *actual, t_list *next)
{
	t_token	*actual_tok;
	t_token	*next_tok;

	actual_tok = (t_token *)actual->content;
	if (next != NULL)
	{
		next_tok = (t_token *)next->content;
		if (actual_tok->token == TOKEN_REDIRECT && next_tok->token == TOKEN_REDIRECT)
			parser->error_code = SYNTAX_ERROR;
		else if (actual_tok->token == TOKEN_REDIRECT && next_tok->token == TOKEN_PIPE)
			parser->error_code = SYNTAX_ERROR;
		else if (actual_tok->token == TOKEN_PIPE && next_tok->token == TOKEN_REDIRECT)
			parser->error_code = SYNTAX_ERROR;
		else if (actual_tok->token == TOKEN_PIPE && next_tok->token == TOKEN_PIPE)
			parser->error_code = SYNTAX_ERROR;
		if (parser->error_code == SYNTAX_ERROR)
			parser->error_value = ft_strdup(actual_tok->value);
	}
	if (next == NULL && (actual_tok->token == TOKEN_REDIRECT || actual_tok->token == TOKEN_PIPE))
	{
		parser->error_code = SYNTAX_ERROR;
		parser->error_value = ft_strdup(actual_tok->value);
	}
}
