/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:30:27 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/19 14:36:39 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_free_2d_char(char **str)
{
	int	n;

	n = 0;
	while (str[n] != NULL)
	{
		free(str[n]);
		n++;
	}
	free(str);
}