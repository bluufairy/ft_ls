/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:01:40 by cpierce           #+#    #+#             */
/*   Updated: 2019/09/30 20:06:11 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				x;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	x = 0;
	if (n == 0 || s1 == s2)
		return (0);
	while (n > ++x)
	{
		if (*str1 != *str2)
			return ((int)(*str1 - *str2));
		if (x < n)
		{
			str1++;
			str2++;
		}
	}
	return ((int)(*str1 - *str2));
}
