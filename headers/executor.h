/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:51:38 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/28 17:13:07 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "struct.h"

//executor
void			get_command_list(t_prog *prog);
void			execute_line(t_prog *prog);
int			execute_single_cmd(t_prog *prog);
void			execute_multi_cmd(t_prog *prog);
//single_cmd_utils
int				dup_correct_fd(t_ast *ast);
void			end_close_fd(t_ast *ast);
//command_utils
int				get_cmd_len(t_ast *ast);
char			*get_correct_path(t_ast *ast, char **env);
int				check_cmd_file_valid(char *file_name);
char			**create_cmd_from_ast(t_ast *ast);
//files
void			open_all_redirec_files(t_prog *prog, t_ast **ast);
void			check_files_valid(t_prog *prog, t_ast *ast);
void			close_all_redirec_files(t_prog *prog, t_ast **ast);
//pipes
int				command_forks(t_prog *prog);
int				execute_process(t_prog *prog, t_ast *ast, int n);
//pipes_fd
void			close_unused_multi(t_prog *prog, int i);
void			end_close_fd_multi(t_ast *ast, int **fds, int n);
int				**pipes_2d_fd(t_prog *prog);
int				dup_correct_fd_multi(t_prog *prog, t_ast *ast, int n);
int				wait_subprocesses(t_prog *prog, int n);
//executor_debug
void			print_cmds(t_list *list_cmd);

#endif
