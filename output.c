/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:06:12 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/20 04:02:30 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"



void	print_items(t_list **items, ls_data *data)
{
	char	**strs;
	int		i;
	
	if (data->t_flag)
		time_sort(items);
	if (data->r_flag)
		rev_list(items);
	if (!data->a_flag)
		remove_hidden(items);
	if (!data->l_flag)
		strs = reg_trans(items);
	else
		strs = l_trans(items);
	i = 0;
	while (strs[i])
	{
		write(1, strs[i], ft_strlen(strs[i]));
		i++;
	}
	
}
#include <stdio.h>
void	norm_out(ls_data *data)
{
	int				i;
	t_list			*items;
	DIR				*cur_dir;
	struct dirent	*add;
	t_list			*cur;

	i = 0;
	while (data->path[i])
	{
		items = NULL;
		cur_dir = opendir(data->path[i]);
		while((add = readdir(cur_dir)))
		{
			//have it skip over items beginning with a "." if the a flag is not set
			cur = ft_lstnew(add, sizeof(struct dirent));
			ft_lstadd(&items, cur);
		}
		print_items(&items, data);
		write(1, "\n\n\n", 3);
		merge_sort(&items, comp_alpha);
		print_items(&items, data);
		
		/*t_list *tmp = items;
		while (tmp)
		{
			printf("%s\n", ((struct dirent *)(tmp->content))->d_name);
			tmp = tmp->next;
		}*/
		
		closedir(cur_dir);
		i++;
	}
}

void	d_it(t_list *next_dirs, void (*f)(ls_data *dat, DIR *d), ls_data *dt)
{
	t_list			*cur;
	t_list			*nxt;
	DIR				*d;

	cur = next_dirs;
	while (cur)
	{
		d = opendir(((char *)(cur->content)));
		nxt = cur->next;
		f(dt, d);
		cur = nxt;
		closedir(d);
	}
}

void	r_out(ls_data *data, DIR *curr_dir)
{
	int				i;
	t_list			*items;
	struct dirent	*add;
	t_list			*cur;
	t_list			*next_d;

	i = 0;
	while (data->path[i])
	{
		next_d = NULL;
		items = NULL;
		while ((add = readdir(curr_dir)))
		{
			cur = ft_lstnew(add, sizeof(struct dirent));
			if (is_dir(*add))
				ft_lstadd(&next_d, ft_lstnew(&(add->d_name), sizeof(char*)));
			ft_lstadd(&items, cur);
		}
		print_items(&items, data);
		while (next_d)
			d_it(next_d, r_out, data);
		free(next_d);
		closedir(curr_dir);
		i++;
	}
}

void	ls_out(ls_data data)
{
	DIR				*first;

	if(data.R_flag)
	{
		first = opendir(data.path[0]);
		r_out(&data, first);
	}
	else
		norm_out(&data);
}
