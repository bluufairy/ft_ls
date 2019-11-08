/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:50:14 by cpierce           #+#    #+#             */
/*   Updated: 2019/09/28 19:53:51 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	cwmax(int n, int fd)
{
	if (n == 2147483647)
	{
		write(fd, "2147483647", 10);
		return (1);
	}
	else if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	else
		return (0);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		nu;

	if (cwmax(n, fd) != 0)
		return ;
	nu = n;
	if (nu < 0)
	{
		write(fd, "-", 1);
		nu *= -1;
	}
	if (nu >= 10)
		ft_putnbr_fd(nu / 10, fd);
	c = (nu % 10) + 48;
	write(fd, &c, 1);
}
