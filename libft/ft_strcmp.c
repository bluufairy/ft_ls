/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:36:31 by cpierce           #+#    #+#             */
/*   Updated: 2019/10/27 03:56:03 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Now accounts for null input.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (0 - (unsigned char)s2[0]);
	else if (!s2)
		return ((unsigned char)s1[0] - 0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
