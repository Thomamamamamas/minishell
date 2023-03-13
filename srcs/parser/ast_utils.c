/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:18:08 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/11 00:01:21 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parser.h"

void	init_ast_iteration(t_parser *parser)
{
	parser->actual = parser->ast;
	parser->actual_pipe = 0;
	if (parser->nb_pipes != 0)
		parser->last_pipe_ast = parser->actual;
}
