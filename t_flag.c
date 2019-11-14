/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 01:56:38 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/13 22:40:11 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 	comp_time(struct dirent *a, struct dirent *b)
{
	struct stat		*a_stat;
	struct stat		*b_stat;
	struct timespec	a_time;
	struct timespec	b_time;

	if (!stat(a->d_name, a_stat) && !stat(b->d_name, b_stat)) //missing full path name?
	{
		a_time = a_stat->st_mtimespec;
		b_time = a_stat->st_mtimespec;
		if (a_time.tv_sec > b_time.tv_sec)
			return (1);
		else if (a_time.tv_sec < b_time.tv_sec)
			return (0);
		else if (a_time.tv_sec == b_time.tv_sec)
		{
			if (a_time.tv_nsec > b_time.tv_nsec)
				return (1);
			else
				return (0);
		}
	}
	else
		exit (0);
	return (-1);
}

void	time_sort(t_list **items)
{
	t_list			*cur;
	t_list			*nxt;

	cur = *items;
	nxt = cur->next;
	if (!cur)
		return ;
	while(cur->next)
	{
		if (comp_time(cur->content, nxt->content))
		{
			
			cur->next = nxt->next;
			nxt->next = cur;
			cur = *items;
		}
		else
			cur = cur->next;
	}
}
