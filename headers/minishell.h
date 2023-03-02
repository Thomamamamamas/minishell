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

typedef struct s_redir
{
	int	infile;
	int	outfile;
	int	heredoc;
	int		append;
}			t_redirec;

typedef struct s_cmd
{
	char		**cmd;
	t_redirec	redirec;
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
//parsing_utils
int				blank_line(char *line);
//free utils
void			free_line_utils(t_lex *lexer, char *line);
void			free_token(void *token);
//command
char			*get_correct_path(t_cmd cmd, char **env);
int				check_cmd_file_valid(char *file_name);
//executor
int				execute_line(t_prog *prog);

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


#endif
