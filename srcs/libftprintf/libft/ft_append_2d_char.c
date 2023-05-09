/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_2d_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:29:02 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/19 14:37:00 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	**ft_append_2d_char(char **array, char *new_el)
{
	int		len;
	int		n;
	char	**res;

	len = 0;
	while (array[len] != NULL)
		len++;
	res = (char **)malloc(sizeof(char *) * len + 1);
	n = 0;
	while (n < len)
	{
		res[n] = ft_strdup(array[n]);
		n++;
	}
	res[n++] = ft_strdup(new_el);
	res[n] = NULL;
	ft_free_2d_char(array);
	return (res);
}
