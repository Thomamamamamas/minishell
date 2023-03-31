/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:19:25 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/31 10:04:40 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include "../srcs/libftprintf/headers/libftprintf.h"
#include "struct.h"


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
