#ifndef MINISHELL_H
#define MINISHELL_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

#include "../srcs/libftprintf/headers/libftprintf.h"
#include "lexer.h"
#include "parser.h"

typedef struct s_redirec
{
	int		infile;
	int		outfile;
	int		heredoc;
	int		append;
	char	*file_name;
}		t_redirec;

typedef struct s_cmd
{
	char		**cmd;
	t_list		*list;
	t_list		*redir_list;
}				t_cmd;


typedef struct s_prog
{
	int		error;
	char	**envp;
	t_cmd	*cmds;
	int		nb_cmd;
	char	**path;
	int		cmd_heredoc;
	int		cmd_infile;
	int		cmd_outfile;
	int		cmd_outfile_a;
}			t_prog;

//init
t_prog			init_shell(char **envp);
char			**get_path_variable(char **envp);
//utils
int				blank_line(char *line);
//free utils
void			free_line_utils(t_lex *lexer, char *line);
void			free_token(void *token);
//create_command
t_list			*ast_to_commands(t_ast *ast, t_list *cmd_list);
t_list			*command_node(t_ast *ast);
t_list			*command_redirection_node(t_ast *actual, t_cmd *cmd);
//command_utils
int				get_nb_arg_cmd(t_ast *ast);
char			*get_correct_path(t_cmd cmd, char **env);
int				check_cmd_file_valid(char *file_name);
t_redirec		*get_last_cmd_redir(t_list *lst, int io);
//pipes
int				pipes_fork(t_prog *prog);
int				pipes_process(t_prog *prog, int n, int **fds);
int				pipe_error_management(t_prog *prog, int code);
//pipes_fd
void			close_unused(t_prog *prog, int i, int **fds);
void			end_close_pipes(t_cmd *cmd, int n, int **fds);
int				**pipes_2d_fd(t_prog *prog);
int				dup_correct_fd(t_prog *prog, int **fds, int n);
int				wait_subprocesses(t_prog *prog, int n, int **fds);
//executor
void			execute_line(t_parser *parser);
//pipes
int				pipes_fork(t_prog *prog);
int				pipes_process(t_prog *prog, int n, int **fds);
int				pipe_error_management(t_prog *prog, int code);
//pipes_fd
void			close_unused(t_prog *prog, int i, int **fds);
void			end_close_pipes(t_cmd *cmd, int n, int **fds);
int				**pipes_2d_fd(t_prog *prog);
int				dup_correct_fd(t_prog *prog, int **fds, int n);
int				wait_subprocesses(t_prog *prog, int n, int **fds);
//error_gestion
void			parsing_error_gestion(t_parser *parser);
//executor_debug
void			print_cmds(t_list *list_cmd);


#endif
