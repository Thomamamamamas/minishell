/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:39:47 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/01 14:50:23 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PARSER_H
#define PARSER_H

#include "../srcs/libftprintf/libft/libft.h"
#include "lexer.h"

typedef enum ast_type
{
	PIPE_NODE,
	CMD_NODE,
	ARG_NODE,
	REDIRECT_INPUT_NODE,
	REDIRECT_OUTPUT_NODE,
	ERROR_NODE
}	e_ast_type;

typedef struct s_ast
{
	e_ast_type		type;
	char			*content;
	struct s_ast	*l_child;
	struct s_ast	*r_child;
}					t_ast;

typedef struct s_parser
{
	struct s_ast	ast;
	struct s_ast	*last_pipe_ast;
	struct s_ast	*actual;
	int				nb_pipes;
	int				actual_pipe;
}					t_parser;

//parsing
t_parser	parsing(t_lex *lexer);
int			check_syntax_error(t_lex *lexer);
t_parser	parse_line(t_lex *lexer);
t_parser	init_parser(t_lex *lexer);
int			get_nb_pipe(t_lex *lexer);
//ast
t_ast		create_ast(t_token *token);
t_ast		*create_child(t_ast *parent, t_token *token, int side);
void		init_pipe_ast_node(t_ast *res);
void		init_first_ast_node(t_ast *res, t_token *token);
void		init_ast_node(t_ast *res, t_ast *parent, t_token *token);
//parsing_debug
void	print_ast(t_ast *node, int space);

#endif
