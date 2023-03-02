/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:35:14 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/01 13:44:49 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lexer.h"

void	print_tokens(t_lex *lexer)
{
	t_list	*lst;
	t_token	*token;

	ft_printf("__________LEXER__________\n");
	lst = lexer->token_lst;
	while (lst)
	{
		token = lst->content;
		ft_printf("value = %s     type = ", token->value);
		switch (token->token)
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
		lst = lst->next;
	}
}
