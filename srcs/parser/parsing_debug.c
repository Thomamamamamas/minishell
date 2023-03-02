/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 04:14:54 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/01 17:32:27 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parser.h"

void	print_ast(t_ast *node, int space)
{
	int	n;

	n = 0;
	if (space == 0)
		ft_printf("__________PARSER__________\n");
	while (n++ < space)
		ft_printf(" ");
	if (!node)
	{
		ft_printf("EOF\n");
		return ;
	}
	switch(node->type)
	{
		case PIPE_NODE:
			ft_printf("PIPE\n");
			print_ast(node->l_child, space + 1);
			print_ast(node->r_child, space + 1);
			break ;
		case REDIRECT_INPUT_NODE:
			ft_printf("REDIRECTION INPUT : %s\n", node->content);
			print_ast(node->l_child, space + 1);
			break ;
		case REDIRECT_OUTPUT_NODE:
			ft_printf("REDIRECTION OUTPUT : %s\n", node->content);
			print_ast(node->l_child, space + 1);
			break ;
		case CMD_NODE:
			ft_printf("COMMANDE : %s ", node->content);
			print_ast(node->l_child, space + 1);
			if (node->l_child == NULL)
				printf("\n");
			break ;
		case ARG_NODE:
			ft_printf("%s ", node->content);
			if (node->l_child == NULL)
				printf("\n");
			print_ast(node->l_child, space + 1);
			break ;
		default:
			ft_printf("\n");
			break ;
	}
}
