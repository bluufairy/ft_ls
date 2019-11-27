/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adddir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 02:09:13 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/25 04:27:05 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		d_len(char **dirs)
{
	int i;

	i = 0;
	while (dirs[i] != NULL)
	{
		i++;
	}
	return (i + 1);
}

int		adddir(ls_data *data, int index, char *name, int c)
{
	char	**old;
	char	**res;
	int		i;
	int		l;
	char	*full_name;
	
	i = 0;
	old = data->path;
	l = d_len(old);
	res = (char **)malloc(sizeof(char *) * (l + 1));
	while (i <= index + c)
	{
		res[i] = old[i];
		i++;
	}
	res[i] = str_join_free3(res[i - 1 - c], "/", name);
	while(i < l)
	{
		res[i + 1] = old[i];
		i++;
	}
	res[i] = NULL;
	free(old);
	data->path = res;
	return (c + 1);
}

void	path_name(char *path)
{
	char	*res;
	
	res = str_join_free3("\n", path, ":\n");
	write(1, res, ft_strlen(res));
}