/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:09:14 by cpierce           #+#    #+#             */
/*   Updated: 2019/09/19 17:06:58 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				x;
	unsigned char		*cdst;
	const unsigned char	*csrc;

	x = 0;
	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	while (x < n)
	{
		cdst[x] = csrc[x];
		if (cdst[x] == (unsigned char)c)
			return (void*)(cdst + 1 + x);
		x++;
	}
	return (NULL);
}
