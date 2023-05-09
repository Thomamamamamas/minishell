/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_2d_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:33:31 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/19 14:34:43 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	**ft_malloc_2d_int(int x, int y)
{
	int	n;
	int	**res;

	n = 0;
	res = (int **)malloc(sizeof(int *) * y);
	while (n < y)
		res[n++] = (int *)malloc(sizeof(int) * x);
	return (res);
}
