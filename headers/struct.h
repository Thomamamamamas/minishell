/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:58:08 by tcasale           #+#    #+#             */
/*   Updated: 2023/05/04 13:47:56 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PROG_H
#define PROG_H

//prog
typedef struct s_prog
{
	struct s_lex	*lexer;
	struct s_parser	*parser;
	char			*pwd;
	int				fd_stdin;
	int				fd_stdout;
	t_list			*cmd_list;
	int				nb_cmd;
	int				**fds;
	int				error_code;
	char			*error_value;
	char			**envp;
	char			**path;
}					t_prog;

//lexer
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

//parser
typedef enum ast_type
{
	PIPE_NODE,
	CMD_NODE,
	BUILTIN_NODE,
	ARG_NODE,
	REDIRECT_INPUT_NODE,
	REDIRECT_OUTPUT_NODE,
	ERROR_NODE
}	e_ast_type;

typedef struct s_ast
{
	e_ast_type		type;
	char			*content;
	int				value;
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

//executor
typedef struct s_redirec
{
	int		infile;
	int		outfile;
	int		heredoc;
	int		append;
	int		fd;
	char	*file_name;
	int		is_invalid;
}			t_redirec;

typedef struct s_cmd
{
	char	**cmd;
	t_list	*redir_list;
}			t_cmd;

#endif
