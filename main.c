/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 05:14:49 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/07 21:06:25 by cpierce          ###   ########.fr       */
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

ls_data parsein(ls_data d, char **av, int ac)
{
	int i;
	int i2;
	ls_data data;

	i = 1;
	i2 = 0;
	data = d;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1])
			data = add_flags(data, av[i]);
		else
			break ;
		i++;
	}
	if (i < ac)
	{
		free(data.path);
		data.path = (char **)malloc(sizeof(char *) * (ac - i + 1));
		data.path[ac - i] = NULL;
	}
	while (i < ac)
	{
		data.path[i2] = ft_strdup(av[i]);
		i++;
		i2++;
	}
	return data;
}

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
	ls_out(data);
	return (0);
}

int scratch(){
	//printf("\nvalid: %s\nl_flag: %d\nR_flag: %d\na_flag: %d\nr_flag: %d\nt_flag: %d\npaths: \n", &data.valid, data.l_flag, data.R_flag, data.a_flag, data.r_flag, data.t_flag);
	//for (int i = 0; data.path[i] != NULL; i++)
	//	printf("%s\n", data.path[i]);
	return 0;
}
