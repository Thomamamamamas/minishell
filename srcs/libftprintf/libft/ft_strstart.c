/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:22:09 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/19 14:37:13 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strstart(char *str, char *start)
{
	int	n;

	n = 0;
	while (start[n] && str[n] && start[n] == str[n])
		n++;
	if (n == ft_strlen(start))
		return (1);
	return (0);
}
