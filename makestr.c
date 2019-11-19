/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 03:29:46 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/18 08:50:24 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			is_dir(struct dirent item)
{
	struct stat	*info;
	char		*path;
	int			res;
	
	res = 0;
	path = ft_strjoin("./", item.d_name);
	if (stat(path, info))
		exit(0);
	if (S_ISDIR(info->st_mode))
		res = 1;
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

static int	comp_alpha(t_list *a, t_list *b)
{
	char	*a_name;
	char	*b_name;
	int		res;
	int		i;

	res = 0;
	i = 0;
	a_name = ((struct dirent *)(a->content))->d_name;
	b_name = ((struct dirent *)(b->content))->d_name;
	while (a_name[i] == b_name[i] && a_name[i] && b_name[i])
		i++;
	if (b_name[i] > a_name[i])
		return 1;
	else
		return 0;
}

void		alpha_sort(t_list **items)
{
	t_list	*cur;
	t_list	*item;
	t_list	*place;
	t_list	*prev;

	cur = *items;
	while(cur)
	{
		if (cur->next)
		{
			item = cur->next;
			place = *items;
			prev = NULL;
			while (comp_alpha(place, item) && place != cur)
			{
				prev = place;
				place = place->next;
			}
			//for some reason it's just removing every other item instead of placing it.
			if (!comp_alpha(place, item))
			{
				cur->next = item->next;
				if (prev)
					prev->next = item;
				item->next = place;
			}
		}
		cur = cur->next;
	}
}

char		**reg_trans(t_list **items)
{
	int		l;
	char	**res;
	t_list	*cur;
	int		i;

	l = list_length(items);
	cur = *items;
	res = (char **)malloc(sizeof(char *) * (l + 1));
	res[l] = NULL;
	i = 0;
	while(cur)
	{
		res[i] = ft_strjoin(((struct dirent*)(cur->content))->d_name, "\n");
		i++;
		cur = cur->next;
	}
	return (res);
}
