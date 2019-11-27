/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:06:12 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/26 21:54:36 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
void	print_items(t_list **items, ls_data *data)
{
	char	**strs;
	int		i;
	
	if (data->t_flag && data->r_flag)
		merge_sort(items, comp_time, 1, data->path[index]);
	else if (data->t_flag)
		merge_sort(items, comp_time, 0);
	else if (data->r_flag)
		merge_sort(items, comp_alpha, 1);
	else
		merge_sort(items, comp_alpha, 0);
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
*/
struct dirent	*list_at(t_list **items, int index)
{
	t_list *res;
	int i;

	res = *items;
	i = 0;
	while (i < index)
	{
		res = res->next;
		i++;
	}
	return ((struct dirent *)(res->content));
}

void	print_items_r(t_list **items, ls_data *data, int index)
{	
	char	**strs;
	int		i;
	int		c;
	
	if (data->t_flag && data->r_flag)
		merge_sort(items, comp_time, 1, data->path[index]);
	else if (data->t_flag)
		merge_sort(items, comp_time, 0, data->path[index]);
	else if (data->r_flag)
		merge_sort(items, comp_alpha, 1, data->path[index]);
	else
		merge_sort(items, comp_alpha, 0, data->path[index]);
	if (!data->l_flag)
		strs = reg_trans(items);
	else
		strs = l_trans(items, data, index);
	i = 0;
	c = 0;
	while (strs[i])
	{
		if (data->R_flag && is_dir(*list_at(items, i), data->path[index]))
			c = adddir(data, index, list_at(items , i)->d_name, c);
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
			if ((!data->a_flag && add->d_name[0] != '.') || data->a_flag)
			{
				cur = ft_lstnew(add, sizeof(struct dirent));
				ft_lstadd(&items, cur);
			}				
		}
		print_items_r(&items, data, i);
		if (data->path[i + 1])
			write (1, str_join_free3("\n", data->path[i + 1], ":\n"),
				ft_strlen(data->path[i + 1]) + 3);
		closedir(cur_dir);
		i++;
	}
}

void	d_it(t_list **next_dirs, void (*f)(ls_data *dat, DIR *d), ls_data *dt)
{
	t_list			*cur;
//	t_list			*nxt;
	DIR				*d;

	cur = *next_dirs;
	while (cur)
	{
		d = opendir(((char *)(cur->content)));
//		cur = cur->next;
		f(dt, d);
//		cur = nxt;
//		*next_dirs = cur;  //may need to just remove the item from the linked list and free it.
//		or this is completely unneccessary due to the nature of recursion.
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
	while (data->path[i]) //not opening a new directory from the originals when done with recursion
	{
		items = NULL;
		next_d = NULL;		
		while((add = readdir(curr_dir)))
		{
			if ((!data->a_flag && add->d_name[0] != '.') || data->a_flag)
			{
				cur = ft_lstnew(add, sizeof(struct dirent));
				printf("%s\n", add->d_name);
				if (is_dir(*add, data->path[i]))
				{
//					ft_lstadd(&next_d, ft_lstnew(add->d_name, sizeof(struct dirent)));
					adddir(data, i, add->d_name, 0);
				}
				ft_lstadd(&items, cur);
			}
		}

		//I could either sort first based off of flags, then make the strings later,
		//Or I could add the directories into the ls_data struct as I process them 
		//in print_items after it's been sorted, then make the whole thing iterative
		//This might be the only idea??? maybe I should just go with it.
		//print_items(&items, data);
		write(1, "\n\n\n", 3);
//		while (next_d)
//			d_it(&next_d, r_out, data);
		closedir(curr_dir);
		i++;
	}
}



/*
void	r_out(ls_data *data, DIR *curr_dir)
{
	int				i;
	t_list			*items;
	struct dirent	*add;
	t_list			*cur;
	t_list			*next_dirs;

	i = 0;
	while(data->path[i] && curr_dir)
	{
		next_d = NULL;
		items = NULL;
		while (curr_dir

}




void	r_out(ls_data *data, DIR *curr_dir)
{
	int				i;
	t_list			*items;
	struct dirent	*add;
	t_list			*cur;
	t_list			*next_d;

	i = 0;
	while (data->path[i] && curr_dir)
	{
		next_d = NULL;
		items = NULL;
		while (curr_dir && (add = readdir(curr_dir)))
		{
			if ((!data->a_flag && add->d_name[0] != '.') || data->a_flag)
			{
			cur = ft_lstnew(add, sizeof(struct dirent));
			if (is_dir(*add))
				ft_lstadd(&next_d, ft_lstnew(&(add->d_name), sizeof(char *)));
			ft_lstadd(&items, cur);
			}
		}
		print_items(&items, data);
		while (next_d)
			d_it(&next_d, r_out, data);
		free(next_d);
		closedir(curr_dir);
		i++;
	}
}
*/
void	ls_out(ls_data data)
{
	norm_out(&data);

	/*
	DIR				*first;
	
	if(data.R_flag)
	{
		first = opendir(data.path[0]);
		r_out(&data, first);
	}
	else
		norm_out(&data);
	*/
}
