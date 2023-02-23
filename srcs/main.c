#include "../headers/minishell.h"

int	main(int argc, char **argv,char **envp)
{
	char	*line;
	t_lex	lexer;
	//t_prog	prog;

	(void)argc;
	(void)argv;
	(void)envp;
	//prog = init_shell(envp);
	while (1)
	{
		rl_on_new_line();
		line = readline("$ ");
		if (line && !blank_line(line))
		{
			line = ft_strclear(line);
			add_history(line);
			lexing(line, &lexer);
			print_tokens(&lexer);
			free(line);
			//execute_line(&prog);
			//free_line(&prog, line);
		}
	}
	return (0);
}
