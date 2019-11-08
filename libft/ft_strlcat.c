/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:47:50 by cpierce           #+#    #+#             */
/*   Updated: 2019/09/19 17:15:52 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t start;
	size_t i;
	size_t ret;

	start = 0;
	ret = 0;
	i = 0;
	while (dst[start] != '\0')
		start++;
	while (src[ret] != '\0')
		ret++;
	if (dstsize <= start)
		ret += dstsize;
	else
		ret += start;
	while (src[i] != '\0' && start + i + 1 < dstsize)
	{
		dst[start + i] = src[i];
		i++;
	}
	dst[start + i] = '\0';
	return (ret);
}
