/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:20:21 by cpierce           #+#    #+#             */
/*   Updated: 2019/09/30 19:59:22 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	cwmax(int n)
{
	if (n == 2147483647)
	{
		write(1, "2147483647", 10);
		return (1);
	}
	else if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (-1);
	}
	else
	{
		return (0);
	}
}

void		ft_putnbr(int n)
{
	int		nu;
	char	c;

	if (cwmax(n) != 0)
		return ;
	nu = n;
	if (nu < 0)
	{
		write(1, "-", 1);
		nu *= -1;
	}
	if (nu >= 10)
		ft_putnbr(nu / 10);
	c = (nu % 10) + '0';
	write(1, &c, 1);
}
