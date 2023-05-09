/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:24:24 by tcasale           #+#    #+#             */
/*   Updated: 2023/03/27 14:26:02 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strclear(char *str)
{
	int		start;
	int		end;
	char	*res;

	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] == ' ' || str[start] == '\t')
		start++;
	while (end > 0 && (str[end] == ' ' || str[end] == '\t'))
		end--;
	if ((end == ft_strlen(str) && start == 0) || end == 0)
		return (str);
	res = ft_substr(str, start, end - start + 1);
	return (res);
}
