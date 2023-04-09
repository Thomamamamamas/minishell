/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:39:47 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/09 15:25:47 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PARSER_H
#define PARSER_H

#include "../srcs/libftprintf/libft/libft.h"
#include "lexer.h"
#include "struct.h"

# define SYNTAX_ERROR	1

//parsing
void		parsing(t_lex *lexer, t_parser *parser);
void		check_syntax_error(t_lex *lexer, t_parser *parser);
void		parse_line(t_lex *lexer, t_parser *parser);
void		init_parser(t_lex *lexer, t_parser *parser);
int			get_nb_pipe(t_lex *lexer);
//syntax_error
void		get_syntax_error(t_parser *parser, t_list *actual, t_list *next);
//ast
t_ast		*create_ast(t_token *token);
t_ast		*create_child(t_ast *parent, t_token *token, int side);
t_ast		*create_child_pipe(t_ast *parent);
void		init_first_ast_node(t_ast *res, t_token *token);
void		init_ast_node(t_ast *res, t_ast *parent, t_token *token);
//ast_utils
void		init_ast_iteration(t_parser *parser);
t_ast		*get_next_pipe(t_parser *parser);
int			is_redirec_node(t_ast *ast);
t_ast		*get_last_redirec_node(t_ast *ast, int mode);
//parsing_debug
void		print_parser(t_parser *parser);
void		print_ast(t_ast *node, int space);

#endif
