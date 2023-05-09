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
	int		opt;
	char	last;

	ast = ast->l_child;
	if (ast && ast->type == ARG_NODE && !ft_strcmp(ast->content, "-n"))
	{
		ast = ast->l_child;
		opt = 1;
	}
	else
		opt = 0;
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
	if (opt == 0)
		ft_putchar('\n');
	return (0);
}

int	pwd(t_prog *prog, int print)
{
	if (prog->pwd != NULL)
		free(prog->pwd);
	prog->pwd = (char *)malloc(sizeof(char) * 1024);
	if (getcwd(prog->pwd, 1024) == NULL)
	{
		ft_putstr_fd("Error: can't get current working directory\n", 2);
		return (1);
	}
	if (print == 1)
		ft_printf("%s\n", prog->pwd);
	return (0);
}

int	env(t_prog *prog, t_ast *ast)
{
	t_list	*lst;

	if (ast->l_child && ast->l_child->type == ARG_NODE)
	{
		ft_putstr_fd("env: ", 2);
		if (ast->l_child->content)
			ft_putstr_fd(ast->l_child->content, 2);
		ft_putstr_fd(": No such file or directory", 2);
		return (127);
	}
	lst = prog->env;
	while (lst)
	{
		if (lst->content)
			ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
	return (0);
}

int	export(t_prog *prog, t_ast *ast)
{
	char	**tmp;
	char	**tmp2;
	ast = ast->l_child;
	while (ast && ast->type == ARG_NODE)
	{
		ast = ast->l_child;
	}
}
