/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:11:52 by cpierce           #+#    #+#             */
/*   Updated: 2019/09/19 16:59:30 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnlen(char *s, size_t maxlen)
{
	int res;

	res = 0;
	while (s[res] != '\0')
		res++;
	if (maxlen == 0 || res == 0)
		return (0);
	else if (res <= maxlen)
		return (res);
	else
		return (res);
}
