/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:51:33 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/31 18:22:52 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
#define MINISHELL_H

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

#include "../srcs/libftprintf/headers/libftprintf.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "struct.h"

//init
t_prog			init_shell(char **envp);
char			**get_path_variable(char **envp);
//utils
int				blank_line(char *line);
//free
void			free_line_utils(t_prog *prog, char *line);
void			free_2d_char(char **array);
void			free_token(void *token);
void			free_ast(t_ast *ast);
//free2
void			free_cmd(void *content);
void			free_redirec(void *content);
//error_gestion
void			parsing_error_gestion(t_parser *parser);

#endif
