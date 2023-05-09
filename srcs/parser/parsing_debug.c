/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 04:14:54 by tcasale           #+#    #+#             */
/*   Updated: 2023/04/06 10:40:29 by tcasale          ###   ########.fr       */
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
			printf(" ");
		}
	}
	if (!node)
	{
		printf("EOF\n");
		return ;
	}
	switch(node->type)
	{
		case PIPE_NODE:
			printf("PIPE\n");
			print_ast(node->l_child, space + 1);
			print_ast(node->r_child, space + 1);
			break ;
		case REDIRECT_INPUT_NODE:
			printf("REDIRECTION INPUT : %s ", node->content);
			print_ast(node->l_child, space);
			break ;
		case REDIRECT_OUTPUT_NODE:
			printf("REDIRECTION OUTPUT : %s ", node->content);
			print_ast(node->l_child, space);
			break ;
		case BUILTIN_NODE:
		case CMD_NODE:
			printf("COMMANDE : %s ", node->content);
			if (!node->l_child)
				printf("\n");
			print_ast(node->l_child, space + 1);
			break ;
		case ARG_NODE:
			printf("%s ", node->content);
			if (!node->l_child)
				printf("\n");
			else if (node->l_child->type != ARG_NODE)
				printf("\n");
			print_ast(node->l_child, space + 1);
			break ;
		default:
			printf("\n");
			break ;
	}
}
