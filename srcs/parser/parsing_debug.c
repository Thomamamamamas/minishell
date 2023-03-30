/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 04:14:54 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/30 12:42:56 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parser.h"

void	print_parser(t_parser *parser)
{
	printf("_________PARSER__________\n");
	print_ast(parser->ast, 0);
}

void	print_ast(t_ast *node, int space)
{
	int	n;

	n = 0;
	if (!node || node->type != ARG_NODE)
	{
		while (n++ < space)
		{
			ft_printf(" ");
		}
	}
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
			ft_printf("REDIRECTION INPUT : %s ", node->content);
			print_ast(node->l_child, space);
			break ;
		case REDIRECT_OUTPUT_NODE:
			ft_printf("REDIRECTION OUTPUT : %s ", node->content);
			print_ast(node->l_child, space);
			break ;
		case CMD_NODE:
			ft_printf("COMMANDE : %s ", node->content);
			if (node->l_child == NULL)
				printf("\n");
			print_ast(node->l_child, space + 1);
			break ;
		case ARG_NODE:
			ft_printf("%s ", node->content);
			if (node->l_child == NULL)
				printf("\n");
			else if (node->l_child->type != ARG_NODE)
				printf("\n");
			print_ast(node->l_child, space + 1);
			break ;
		default:
			ft_printf("\n");
			break ;
	}
}
