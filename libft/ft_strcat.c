/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:36:48 by cpierce           #+#    #+#             */
/*   Updated: 2019/09/20 13:20:10 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	int start;
	int i;

	start = 0;
	i = 0;
	while (s1[start] != '\0')
		start++;
	while (s2[i] != '\0')
	{
		s1[start + i] = s2[i];
		i++;
	}
	s1[start + i] = '\0';
	return (s1);
}
