/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 03:29:46 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/08 11:02:31 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			is_dir(struct dirent item)
{
	struct stat	info;
	char		*path;
	
	path = ft_strjoin("./", item.d_name);
	if (stat(path, extra))
		exit(0);
	if ()//check if dir
		res = 1;
	else
		res = 0;
	free(path);
	return (res);
}

int			list_length(t_list **items)
{
	int		count;
	t_list	*cur;

	count = 0;
	cur = *items;
	while(cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}


char		**reg_trans(**t_list items)
{
	int		l;
	char	**res;
	t_list	*cur;
	int		i;

	l = list_length(items);
	res = (char **)malloc(sizeof(char *) + 1);
	res[l] = NULL;
	i = 0;
	while(cur)
	{
		res[i] = cur->data.d_name;
		i++;
		cur = cur->next;
	}
	return (res);
}
