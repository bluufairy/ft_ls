/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:47:03 by cpierce           #+#    #+#             */
/*   Updated: 2019/10/03 17:31:26 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ret_max(const char *s)
{
	if (ft_strcmp("2147483647", s) == 0)
		return (2147483647);
	else if (ft_strcmp("-2147483648", s) == 0)
		return (-2147483648);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int neg;
	int i;
	int res;

	neg = 1;
	i = 0;
	res = 0;
	if (ret_max(str) != 0)
		return (ret_max(str));
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
				str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * neg);
}
