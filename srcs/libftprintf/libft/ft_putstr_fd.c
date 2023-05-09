/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:20:48 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 15:34:33 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	n;

	if (!s)
		return ;
	n = 0;
	while (s[n])
	{
		ft_putchar_fd(s[n], fd);
		n++;
	}
}
/*
int	main()
{
	ft_putstr_fd("bonjour pute", 1);
	return(0);
}
*/
