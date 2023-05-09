/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:58:18 by tcasale           #+#    #+#             */
/*   Updated: 2023/05/04 09:18:07 by tcasale          ###   ########.fr       */
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
		line = readline("$ ");
		if (line && !blank_line(line))
		{
			add_history(line);
			line = ft_strclear(line);
			prog.lexer = (t_lex *)malloc(sizeof(t_lex));
			lexing(line, prog.lexer);
			//print_tokens(prog.lexer);
			prog.parser = (t_parser *)malloc(sizeof(t_parser));
			parsing(prog.lexer, prog.parser);
			parsing_error_gestion(prog.parser);
			if (prog.parser->error_code == 0)
			{
				print_parser(prog.parser);
				execute_line(&prog);
				free_parser(&prog);
			}
			error_gestion(&prog);
			free(line);
		}
	}
	return (0);
}
