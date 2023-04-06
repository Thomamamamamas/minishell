/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:58:18 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/06 09:21:50 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/minishell.h"

int	main(int argc, char **argv,char **envp)
{
	char		*line;
	t_prog		prog;

	(void)argc;
	(void)argv;
	(void)envp;
	prog = init_shell(envp);
	while (1)
	{
		rl_on_new_line();
		line = readline("$ ");
		if (line && !blank_line(line))
		{
			line = ft_strclear(line);
			add_history(line);
			prog.lexer = (t_lex *)malloc(sizeof(t_lex));
			lexing(line, prog.lexer);
			print_tokens(prog.lexer);
			prog.parser = (t_parser *)malloc(sizeof(t_parser));
			parsing(prog.lexer, prog.parser);
			free_lexer(&prog);
			if (prog.parser->error_code == 0)
			{
				print_parser(prog.parser);
				//print_cmds(prog->cmd_list);
				execute_line(&prog);
				free_parser(&prog);
			}
			else
				parsing_error_gestion(prog.parser);
			free_line_utils(line);
		}
	}
	return (0);
}
