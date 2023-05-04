/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:54:51 by tcasale           #+#    #+#             */
/*   Updated: 2023/05/04 14:16:12 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

int	echo(t_ast *ast)
{
	int		n;
	char	last;

	ast = ast->l_child;
	while (ast && ast->type == ARG_NODE)
	{
		n = 0;
		while (ast->content[n])
		{
			if (n < ft_strlen(ast->content) && ast->content[n] == '\\' && ast->content[n + 1] == '\\')
				ft_putchar(ast->content[n]);
			else if (ast->content[n] != '\\' && last != '\\')
				ft_putchar(ast->content[n]);
			last = ast->content[n];
			n++;
		}
		if (ast->l_child && ast->l_child->type == ARG_NODE)
			ft_putchar(' ');
		ast = ast->l_child;
	}
	return (0);
}

int	pwd(t_prog *prog)
{
	if (prog->pwd != NULL)
		free(prog->pwd);
	prog->pwd = (char *)malloc(sizeof(char) * 1024);
	if (getcwd(prog->pwd, 1024) == NULL)
	{
		ft_putstr_fd("Error: can't get current working directory\n", 2);
		return (1);
	}
	return (0);
}
