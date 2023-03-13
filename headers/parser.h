/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:39:47 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/12 06:08:14 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PARSER_H
#define PARSER_H

#include "../srcs/libftprintf/libft/libft.h"
#include "lexer.h"

# define SYNTAX_ERROR	1

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
	struct s_ast	*ast;
	struct s_ast	*last_pipe_ast;
	struct s_ast	*actual;
	int				nb_pipes;
	int				actual_pipe;
	int				error_code;
	char			*error_value;
}					t_parser;

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
t_ast		*get_next_ast_node(t_parser *parser);
void		init_ast_iteration(t_parser *parser);
int			last_node_was_pipe(t_parser *parser);
//parsing_debug
void	print_ast(t_ast *node, int space);

#endif
