/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:14:28 by cpierce           #+#    #+#             */
/*   Updated: 2019/09/19 17:48:25 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int ret;

	i = 0;
	ret = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			ret = i;
		i++;
	}
	if ((char)c == '\0')
		return ((char*)&s[i]);
	else if (ret != -1)
		return ((char*)&s[ret]);
	else
		return (NULL);
}
