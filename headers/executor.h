/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:51:38 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/31 12:33:39 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "struct.h"

//executor
void			execute_line(t_prog *prog);
//create_command
t_list			*ast_to_commands(t_ast *ast, t_list *cmd_list);
t_list			*command_node(t_ast *ast);
t_list			*command_redirection_node(t_ast *actual, t_cmd *cmd);
int				is_cmd_node(t_ast *ast);
//command_utils
int				get_nb_arg_cmd(t_ast *ast);
char			*get_correct_path(t_cmd cmd, char **env);
int				check_cmd_file_valid(char *file_name);
t_redirec		*get_last_cmd_redir(t_list *lst, int io);
//files
void			open_all_files(t_list *cmd_list);
void			open_file(t_list *lst);
int				open_outfile(t_redirec *redirec);
//pipes
int				command_forks(t_prog *prog);
int				execute_process(t_prog *prog, int n, int **fds);
//pipes_fd
void			close_unused(t_prog *prog, int i, int **fds);
void			end_close_pipes(t_cmd *cmd, int n, int **fds);
int				**pipes_2d_fd(t_prog *prog);
int				dup_correct_fd(t_prog *prog, int **fds, int n);
int				wait_subprocesses(t_prog *prog, int n, int **fds);
//executor_debug
void			print_cmds(t_list *list_cmd);

#endif