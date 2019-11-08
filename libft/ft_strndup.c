/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:49:47 by cpierce           #+#    #+#             */
/*   Updated: 2019/09/29 01:36:09 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*res;
	int		i;
	size_t	s;

	s = ft_strlen((char *)s1);
	if (s < n)
		return (ft_strdup(s1));
	if (!(res = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (n > 0)
	{
		res[i] = s1[i];
		n--;
		i++;
	}
	res[i] = '\0';
	return (res);
}
