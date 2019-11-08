/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:15:23 by cpierce           #+#    #+#             */
/*   Updated: 2019/09/29 19:54:51 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

/*
** Returns a new allocated string containing the reversed contents of the input.
*/

char	*ft_strrev(char *s)
{
	int		len;
	char	*res;
	int		i;

	len = ft_strlen(s);
	i = 0;
	res = (char *)malloc(sizeof(char) * (len + 1));
	res[len] = '\0';
	len--;
	while (len >= 0)
	{
		res[i] = s[len];
		i++;
		len--;
	}
	return ((char*)res);
}
