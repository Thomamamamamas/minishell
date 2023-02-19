#include "../headers/minishell.h"

int	main(int argc, char **argv,char **envp)
{
	char	*str;
	t_prog	prog;

	(void)argc;
	(void)argv;
	prog = init_shell(envp);
	while (1)
	{
		rl_on_new_line();
		str = readline("$ ");
		if (str && !blank_line(str))
		{
			add_history(str);
			parse_line(&prog, str);
			//execute_line(&prog);
			free_line(&prog, str);
		}
	}
	return (0);
}
