/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:50:31 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/28 15:00:16 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

void	open_all_redirec_files(t_prog *prog, t_ast **ast)
{
	t_ast	*actual;

	actual = *ast;
	if (actual->l_child && (actual->type == REDIRECT_INPUT_NODE || actual->type == REDIRECT_OUTPUT_NODE))
	{
		if (actual->l_child->content && access(actual->l_child->content, F_OK) == 0)
		{
			if (ft_strcmp(actual->content, "<") == 0)
				actual->value = open(actual->l_child->content, O_RDONLY);
			if (ft_strcmp(actual->content, ">>") == 0)
				actual->value = open(actual->l_child->content, O_RDWR | O_APPEND);
			if (ft_strcmp(actual->content, ">") == 0)
				actual->value = open(actual->l_child->content, O_RDWR | O_TRUNC);
		}
		else if (actual->l_child->content && ft_strcmp(actual->content, "<") != 0)
			actual->value = open(actual->l_child->content, O_RDWR | 0644);
		else if (prog->error_code == 0)
		{
			prog->error_code = 1;
			prog->error_value = ft_strdup(actual->l_child->content);
		}
	}
	if (actual && actual->l_child)
		open_all_redirec_files(prog, &actual->l_child);
	if (actual && actual->r_child)
		open_all_redirec_files(prog, &actual->r_child);
}

void	check_files_valid(t_prog *prog, t_ast *ast)
{
	if (ast->type == REDIRECT_INPUT_NODE || ast->type == REDIRECT_OUTPUT_NODE)
	{
		if (ast->value < 0 && prog->error_code == 0)
		{
			prog->error_code = 2;
			prog->error_value = ft_strdup(ast->content);
		}
	}
	if (ast && ast->l_child)
		check_files_valid(prog, ast->l_child);
	if (ast && ast->r_child)
		check_files_valid(prog, ast->r_child);
}
