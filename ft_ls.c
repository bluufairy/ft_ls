/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:00:47 by cpierce           #+#    #+#             */
/*   Updated: 2019/10/30 20:14:03 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	apply_flags(char* res, char *flg)
{
	int i = 0;
	while (flg[i])
	{
		if (flg[i] == 'l')
			l_conv(res);
		if (flg[i] == 'R')
			R_conv(res);
		if (flg[i] == 'a')
			a_conv(res);
		if (flg[i] == 'r')
			r_conv(res);
		if (flg[i] == 't')
			t_conv(res);
		i++;
	}
}

char	*initialize(char *path)
{

}

int		main(int argc, int argv)
{
	char	*res;
	int		i;
	char	*flg;
	char	*path;

	i = 1;
	path = "..";
	

	res = initialize(path);
	while (i <= argc)
	{
		flg = get_flag(argv[i]);
		if (a == NULL)
		{
			write(1, "Invalid Flag.\n", 1);
		}
		i++;
		apply_flags(res, flg);
	}
}
