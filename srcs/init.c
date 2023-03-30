#include "../headers/minishell.h"

t_prog	init_shell(char **envp)
{
	t_prog	prog;

	prog.path = get_path_variable(envp);
	prog.envp = envp;
	prog.lexer = (t_lex *)malloc(sizeof(t_lex));
	prog.parser = (t_parser *)malloc(sizeof(t_parser));
	return (prog);
}

char	**get_path_variable(char **envp)
{
	int		n;
	char	*tmp;
	char	**res;

	n = 0;
	while (envp[n] && ft_strnstr(envp[n], "PATH=", ft_strlen(envp[n])) == 0)
		n++;
	if (envp[n] != NULL)
	{
		if (ft_strnstr(envp[n], "PATH=", ft_strlen(envp[n])) != 0)
		{
			tmp = ft_substr(envp[n], 5, 500);
			res = ft_split(tmp, ':');
			free(tmp);
			return (res);
		}
	}
	res = (char **)malloc(sizeof(char *) * 1);
	res[0] = NULL;
	return (res);
}
