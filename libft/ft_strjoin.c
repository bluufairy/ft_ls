/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:56:52 by cpierce           #+#    #+#             */
/*   Updated: 2019/10/03 17:54:02 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		l;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(res = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	ft_strcpy(res, (char *)s1);
	ft_strcat(res, (char *)s2);
	return (res);
}
