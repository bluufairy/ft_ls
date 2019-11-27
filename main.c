/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 05:14:49 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/20 02:50:35 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

ls_data set_empty(void)
{
	ls_data data;

	data.valid = '\0';
	data.l_flag = 0;
	data.R_flag = 0;
	data.a_flag = 0;
	data.r_flag = 0;
	data.t_flag = 0;
	data.path = (char **)malloc(sizeof(char *) * 2);
	data.path[0] = ".";
	data.path[1] = NULL;
	data.valid2 = "\0";

	return data;
}

ls_data add_flags(ls_data d, char *flg)
{
	int i;
	ls_data data;

	data = d;
	i = 1;
	while (flg[i])
	{
		if (flg[i] == 'l')
			data.l_flag = 1;
		else if (flg[i] == 'R')
			data.R_flag = 1;
		else if (flg[i] == 'a')
			data.a_flag = 1;
		else if (flg[i] == 'r')
			data.r_flag = 1;
		else if (flg[i] == 't')
			data.t_flag = 1;
		else
		{
			data.valid = flg[i];
			break ;
		}
		i++;
	}
	return data;
}

char	*check_valid(char *di)
{
	DIR *d;

	d = opendir(di);
	if (d)
	{
		return ("\0");
		closedir(d);
	}
	else
		return di;		
	//return (ft_strdup(di));
}

ls_data parsein(ls_data d, char **av, int ac)
{
	int i;
	int i2;
	ls_data data;

	i = 0;
	i2 = 0;
	data = d;
	while (++i < ac)
		if (av[i][0] == '-' && av[i][1])
			data = add_flags(data, av[i]);
		else
			break ;
	if (i < ac)
	{
		free(data.path);
		data.path = (char **)malloc(sizeof(char *) * (ac - i + 1));
		data.path[ac - i] = NULL;
	}
	while (i < ac)
	{
		data.path[i2] = ft_strdup(av[i]);
		data.valid2 = check_valid(av[i]);
		i++;
		i2++;
	}
	return data;
}

#include <stdio.h>
int main(int ac, char **av)
{
	ls_data data;

	data = set_empty();
	if (ac < 1)
		write (1, "Error\n", 6);
	else if (ac > 1)
		data = parsein(data, av, ac);
	if (data.valid != '\0')
	{
		write(1, "ls: illegal option -- ", 22);
		write(1, &data.valid, 1);
		write(1, "\nusage: ls [-alRrt] [file ...]", 30);
	}
	else if (data.valid2[0] != '\0')
	{
		write(1, "ls: ", 4);
		write(1, data.valid2, ft_strlen(data.valid2));
		write(1, ": No such file or directory\n", 28);
	}
	else
		ls_out(data);
	return 0;
}
