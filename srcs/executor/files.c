/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:50:31 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/09 12:20:49 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/minishell.h"

void	open_all_redirec_files(t_ast **ast)
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
	}
	if (actual && actual->l_child)
		open_all_redirec_files(&actual->l_child);
	if (actual && actual->r_child)
		open_all_redirec_files(&actual->r_child);
}

int	files_not_valid(t_ast *ast)
{
	int	res;

	res = 0;
	if (ast->type == REDIRECT_INPUT_NODE || ast->type == REDIRECT_OUTPUT_NODE)
	{
		if (ast->value == -1)
			res = 1;
	}
	if (ast && ast->l_child)
		res = res + files_not_valid(ast->l_child);
	if (ast && ast->r_child)
		res = res + files_not_valid(ast->r_child);
	return (res);
}
