/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:40:46 by cpierce           #+#    #+#             */
/*   Updated: 2019/09/30 18:01:19 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	int					x;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	x = 0;
	if (s == d)
		return (dst);
	else if (d > s)
	{
		while ((int)len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (x < (int)len)
		{
			d[x] = s[x];
			x++;
		}
	}
	return (dst);
}
