/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:16:10 by cpierce           #+#    #+#             */
/*   Updated: 2019/10/03 17:53:41 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	int		num;
	char	*res;

	num = n;
	len = 0;
	neg = n < 0 ? 1 : 0;
	while (num /= 10)
		len++;
	len += 1 + neg;
	num = n < 0 ? n * -1 : n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[0] = '-';
	res[len] = '\0';
	while (--len >= neg)
	{
		res[len] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}
