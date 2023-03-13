/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:19:25 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/02 18:50:46 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include "../srcs/libftprintf/headers/libftprintf.h"

typedef enum token_type
{
	TOKEN_PIPE,
	TOKEN_REDIRECT,
	TOKEN_WORD,
	TOKEN_EOF,
}	etoken_type;

typedef struct s_token
{
	etoken_type		token;
	char			*value;
}					t_token;

typedef struct s_lex
{
	t_list	*token_lst;
}	t_lex;

void			lexing(char *line, t_lex *lexer);
t_token			*create_token(char *line, int n);
char			*get_token_value(char *line, int start);
etoken_type		get_token_type(char *value);
//utils
int				len_redirection(char *line, char c, int n);
int				is_space(char c);
//debug
void			print_tokens(t_lex *lexer);

#endif
