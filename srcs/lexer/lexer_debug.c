/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:35:14 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/23 19:45:52 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lexer.h"

void	print_tokens(t_lex *lexer)
{
	int	n;

	n = 0;
	while (n < lexer->len)
	{
		ft_printf("value = %s     type = ", lexer->tokens[n].value);
		switch (lexer->tokens[n].token)
		{
			case TOKEN_EOF: 
				printf("EOF\n");
				break;
			case TOKEN_REDIRECT: 
				printf("REDIRECT\n");
				break;
			case TOKEN_PIPE: 
				printf("PIPE\n");
				break;
			case TOKEN_WORD: 
				printf("WORD\n");
				break;
		}
		n++;
	}
}
