/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 20:54:00 by cpierce           #+#    #+#             */
/*   Updated: 2019/10/03 17:52:15 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**new_arr(char **arr, int items)
{
	char	**res;
	int		i;

	res = (char **)malloc(sizeof(char *) * (items + 1));
	i = 0;
	while (i < items)
	{
		res[i] = ft_strdup(arr[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	int		place;
	int		a;
	int		b;
	char	**res;
	int		count;

	place = 0;
	count = 0;
	if (!s)
		return (NULL);
	if ((res = (char **)malloc(sizeof(char *) * ft_strlen((char *)s))))
	{
		while ((size_t)place < ft_strlen((char *)s))
		{
			while (s[place] == c && s[place])
				place++;
			a = place;
			while (s[place] != c && s[place])
				place++;
			b = place;
			res[count++] = ((b - a) > 0) ? ft_strsub(s, a, b - a) : res[count];
		}
		res = ((b - a) > 0) ? new_arr(res, count) : new_arr(res, count - 1);
	}
	return (res);
}
