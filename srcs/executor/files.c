/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:50:31 by tcasale           #+#    #+#             */
/*   Updated: 2023/05/04 09:18:08 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

void	open_all_redirec_files(t_prog *prog, t_ast *ast)
{
	t_ast	*actual;

	actual = ast;
	if (actual->l_child && is_redirec_node(ast))
	{
		if (actual->l_child->content && access(actual->l_child->content, F_OK) == 0)
		{
			if (is_last_redirec(actual))
			{
				if (ft_strcmp(actual->content, "<") == 0)
					actual->value = open(actual->l_child->content, O_RDONLY);
				if (ft_strcmp(actual->content, ">>") == 0)
					actual->value = open(actual->l_child->content, O_RDWR | O_APPEND);
				if (ft_strcmp(actual->content, ">") == 0)
					actual->value = open(actual->l_child->content, O_RDWR | O_TRUNC);
			}
		}
		else if (is_last_redirec(actual) && actual->type != REDIRECT_INPUT_NODE)
			actual->value = open(actual->l_child->content, O_CREAT | O_RDWR, 0644);
		else if (prog->error_code == 0)
		{
			prog->error_code = 1;
			prog->error_value = ft_strdup(actual->l_child->content);
		}
	}
	if (actual && actual->l_child)
		open_all_redirec_files(prog, actual->l_child);
	if (actual && actual->r_child)
		open_all_redirec_files(prog, actual->r_child);
}

void	close_all_redirec_files(t_ast *ast)
{
	t_ast	*actual;

	actual = ast;
	if (actual->l_child && is_redirec_node(actual))
	{
		if (actual->l_child->content && actual->value >= 0)
			close(actual->value);
	}
	if (actual && actual->l_child)
		close_all_redirec_files(actual->l_child);
	if (actual && actual->r_child)
		close_all_redirec_files(actual->r_child);
}

void	check_files_valid(t_prog *prog, t_ast *ast)
{
	if (is_last_redirec(ast))
	{
		if (ast->value < 0 && prog->error_code == 0)
		{
			prog->error_code = 2;
			if (ast->l_child)
				prog->error_value = ft_strdup(ast->l_child->content);
		}
	}
	if (ast && ast->l_child)
		check_files_valid(prog, ast->l_child);
	if (ast && ast->r_child)
		check_files_valid(prog, ast->r_child);
}

int	is_last_redirec(t_ast *ast)
{
	int	outfile;

	if (!is_redirec_node(ast))
		return (0);
	if (ft_strcmp(ast->content, ">") == 0)
		outfile = 1;
	else if (ft_strcmp(ast->content, ">>") == 0)
		outfile = 1;
	else
		outfile = 0;
	ast = ast->l_child;
	while (ast)
	{
		if (is_redirec_node(ast))
		{
			if (ft_strcmp(ast->content, "<") == 0 && outfile == 0)
				return (0);
			else if (ft_strcmp(ast->content, ">") == 0 && outfile == 1)
				return (0);
			else if (ft_strcmp(ast->content, ">>") == 0 && outfile == 1)
				return (0);
		}
		ast = ast->l_child;
	}
	return (1);
}
