/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:06:12 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/07 23:34:26 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	norm_out(ls_data data)
{
	int				i;
	t_list			**items;
	DIR				cur_dir;
	struct dirent	*add;
	t_list			*cur;

	i = 0;
	while (data.paths[i])
	{
		items = (t_list**)malloc(sizeof(t_list*));
		cur_dir = opendir(data.paths[i]);
		while((add = readdir(curr_dir)))
		{
			cur = ft_lstnew(add, sizeof(dirent*));
			ft_lstadd(items, cur);
		}
		print_items(items, data);
		closedir(curr_dir);
		i++;
	}
}

void	print_items(t_list **items, ls_data data)
{
	if (data.t_flag)
		time_sort(items);
	if (data.r_flag)
		rev_list(items);
	if (!data.a_flag)
		remove_hidden(items);
	
}

void	dir_iter(t_list *next_dirs, void (*f)(ls_data data, DIR d), ls_data dat)
{
	t_list			*cur;
	t_list			*nxt;

	cur = lst;
	while (cur)
	{
		nxt = cur->next;
		f(dat, cur->data);
		cur = nxt;
	}
}

void	r_out(ls_data data, DIR curr_dir)
{
	int				i;
	t_list			**items;
	struct dirent	*add;
	t_list			*cur;
	t_list			**next_dirs;

	i = 0;
	while (data.paths[i])
	{
		next_dirs = (t_list*)malloc(sizeof(t_list*));
		items = (t_list**)malloc(sizeof(t_list*));
		while ((add = readdir(curr_dir)))
		{
			cur = ft_lstnew(add, sizeof(dirent*));
			if (add) //is a directory)
				ft_lstadd(next_dirs, cur);
			ft_lstadd(items, cur);
		}
		print_items(items, data);
		while (*next_dirs)
			dir_iter(*next_dirs, r_out);
		closedir(curr_dir);
		i++:
	}
}

void	ls_out(ls_data data)
{
	DIR				first;

	if(data.R_flag)
	{
		first = opendir(data.path[0]);
		r_out(data, first, 0);
	}
	else
		norm_out(data);
}
